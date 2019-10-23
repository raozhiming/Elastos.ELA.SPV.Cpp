// Copyright (c) 2012-2018 The Elastos Open Source Project
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "AssetDataStore.h"

#include <SDK/Common/ErrorChecker.h>
#include <SDK/Common/Log.h>

namespace Elastos {
	namespace ElaWallet {

		AssetDataStore::AssetDataStore(Sqlite *sqlite) :
			TableBase(sqlite) {
			InitializeTable(ASSET_DATABASE_CREATE);
			InitializeTable("drop table if exists " + ASSET_OLD_TABLE_NAME + ";");
		}

		AssetDataStore::AssetDataStore(SqliteTransactionType type, Sqlite *sqlite) :
			TableBase(type, sqlite) {
			InitializeTable(ASSET_DATABASE_CREATE);
			InitializeTable("drop table if exists " + ASSET_OLD_TABLE_NAME + ";");
		}

		AssetDataStore::~AssetDataStore() {

		}

		bool AssetDataStore::PutAsset(const std::string &iso, const AssetEntity &asset) {
			return DoTransaction([&iso, &asset, this]() {
				AssetEntity existAsset;

				if (SelectAsset(asset.AssetID, existAsset))
					return UpdateAsset(iso, asset);

				return InsertAsset(iso, asset);
			});
		}

		bool AssetDataStore::DeleteAsset(const std::string &assetID) {
			return DoTransaction([&assetID, this]() {
				std::string sql;

				sql = "DELETE FROM " + ASSET_TABLE_NAME + " WHERE " + ASSET_COLUMN_ID + " = ?;";

				sqlite3_stmt *stmt;
				if (!_sqlite->Prepare(sql, &stmt, nullptr)) {
					Log::error("Prepare sql {}", sql);
					return false;
				}

				if (!_sqlite->BindText(stmt, 1, assetID, nullptr)) {
					Log::error("bind text");
					return false;
				}

				if (SQLITE_DONE != _sqlite->Step(stmt)) {
					Log::error("step");
					return false;
				}

				if (!_sqlite->Finalize(stmt)) {
					Log::error("finalize");
					return false;
				}

				return true;
			});
		}

		bool AssetDataStore::DeleteAllAssets() {
			return DoTransaction([this]() {
				std::string sql;

				sql = "DELETE FROM " + ASSET_TABLE_NAME + ";";

				if (!_sqlite->exec(sql, nullptr, nullptr)) {
					Log::error("exec sql: {}", sql);
					return false;
				}

				return true;
			});
		}

		bool AssetDataStore::GetAssetDetails(const std::string &assetID, AssetEntity &asset) const {
			bool found = false;

			return DoTransaction([&assetID, &asset, &found, this]() {
				return SelectAsset(assetID, asset);
			});
		}

		std::vector<AssetEntity> AssetDataStore::GetAllAssets() const {
			std::vector<AssetEntity> assets;

			DoTransaction([&assets, this]() {
				AssetEntity asset;
				std::string sql;

				sql = "SELECT " + ASSET_COLUMN_ID + ", " + ASSET_AMOUNT + ", " + ASSET_BUFF + " FROM " +
					  ASSET_TABLE_NAME + ";";

				sqlite3_stmt *stmt;
				if (!_sqlite->Prepare(sql, &stmt, nullptr)) {
					Log::error("prepare sql: {}", sql);
					return false;
				}

				while (SQLITE_ROW == _sqlite->Step(stmt)) {

					asset.AssetID = _sqlite->ColumnText(stmt, 0);
					asset.Amount.setDec(_sqlite->ColumnText(stmt, 1));

					const uint8_t *pdata = (const uint8_t *) _sqlite->ColumnBlob(stmt, 2);
					size_t len = (size_t) _sqlite->ColumnBytes(stmt, 2);

					asset.Asset.assign(pdata, pdata + len);

					assets.push_back(asset);
				}

				if (!_sqlite->Finalize(stmt)) {
					Log::error("finalize");
					return false;
				}

				return true;
			});

			return assets;
		}

		void AssetDataStore::flush() {
			_sqlite->flush();
		}

		bool AssetDataStore::SelectAsset(const std::string &assetID, AssetEntity &asset) const {
			bool found = false;
			std::string sql;

			sql = "SELECT " + ASSET_AMOUNT + ", " + ASSET_BUFF + " FROM " + ASSET_TABLE_NAME + " WHERE " +
				  ASSET_COLUMN_ID + " = ?;";

			sqlite3_stmt *stmt;
			if (!_sqlite->Prepare(sql, &stmt, nullptr)) {
				Log::error("prepare sql: {}", sql);
				return false;
			}

			if (!_sqlite->BindText(stmt, 1, assetID, nullptr)) {
				Log::error("bind text");
				return false;
			}

			while (SQLITE_ROW == _sqlite->Step(stmt)) {
				found = true;

				asset.AssetID = assetID;
				asset.Amount.setDec(_sqlite->ColumnText(stmt, 0));

				const uint8_t *pdata = (const uint8_t *) _sqlite->ColumnBlob(stmt, 1);
				size_t len = (size_t) _sqlite->ColumnBytes(stmt, 1);

				asset.Asset.assign(pdata, pdata + len);
			}

			if (!_sqlite->Finalize(stmt)) {
				Log::error("finalize");
				return false;
			}

			return found;
		}

		bool AssetDataStore::InsertAsset(const std::string &iso, const AssetEntity &asset) {
			std::string sql;

			sql = "INSERT INTO " + ASSET_TABLE_NAME + "(" + ASSET_COLUMN_ID + "," +
				  ASSET_AMOUNT + "," + ASSET_BUFF + "," + ASSET_ISO + ") VALUES (?, ?, ?, ?);";

			sqlite3_stmt *stmt;
			if (!_sqlite->Prepare(sql, &stmt, nullptr)) {
				Log::error("prepare sql: {}", sql);
				return false;
			}

			if (!_sqlite->BindText(stmt, 1, asset.AssetID, nullptr) ||
				!_sqlite->BindText(stmt, 2, asset.Amount.getDec(), nullptr) ||
				!_sqlite->BindBlob(stmt, 3, asset.Asset, nullptr) ||
				!_sqlite->BindText(stmt, 4, iso, nullptr)) {
				Log::error("bind args");
				return false;
			}

			if (SQLITE_DONE != _sqlite->Step(stmt)) {
				Log::error("step");
				return false;
			}

			if (!_sqlite->Finalize(stmt)) {
				Log::error("finalize");
				return false;
			}

			return true;
		}

		bool AssetDataStore::UpdateAsset(const std::string &iso, const AssetEntity &asset) {
			std::string sql;

			sql = "UPDATE " + ASSET_TABLE_NAME + " SET "
				  + ASSET_AMOUNT + " = ?, "
				  + ASSET_BUFF + " = ?, "
				  + ASSET_ISO + " = ?"
				  + " WHERE " + ASSET_COLUMN_ID + " = ?;";

			sqlite3_stmt *stmt;
			if (!_sqlite->Prepare(sql, &stmt, nullptr)) {
				Log::error("prepare sql: {}" + sql);
				return false;
			}

			if (!_sqlite->BindText(stmt, 1, asset.Amount.getDec(), nullptr) ||
				!_sqlite->BindBlob(stmt, 2, asset.Asset, nullptr) ||
				!_sqlite->BindText(stmt, 3, iso, nullptr) ||
				!_sqlite->BindText(stmt, 4, asset.AssetID, nullptr)) {
				Log::error("bind args");
				return false;
			}

			if (SQLITE_DONE != _sqlite->Step(stmt)) {
				Log::error("step");
				return false;
			}

			if (!_sqlite->Finalize(stmt)) {
				Log::error("finalize");
				return false;
			}

			return true;
		}

	}
}
