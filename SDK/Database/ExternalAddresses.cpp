// Copyright (c) 2012-2018 The Elastos Open Source Project
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <SDK/Common/ParamChecker.h>
#include "ExternalAddresses.h"

namespace Elastos {
	namespace ElaWallet {

		ExternalAddresses::ExternalAddresses(Sqlite *sqlite) :
			TableBase(sqlite) {
			initializeTable(MB_DATABASE_CREATE);
		}

		ExternalAddresses::ExternalAddresses(SqliteTransactionType type, Sqlite *sqlite) :
			TableBase(type, sqlite) {
			initializeTable(MB_DATABASE_CREATE);
		}

		ExternalAddresses::~ExternalAddresses() {

		}

		bool ExternalAddresses::putAddress(uint32_t startIndex, const std::string &address) {
			return doTransaction([startIndex, &address, this]() {
				this->putAddressInternal(startIndex, address);
			});
		}

		bool ExternalAddresses::putAddresses(uint32_t startIndex, const std::vector<std::string> &addresses) {
			return doTransaction([startIndex, &addresses, this]() {
				for (size_t i = 0; i < addresses.size(); ++i) {
					this->putAddressInternal(startIndex + i, addresses[i]);
				}
			});
		}

		bool ExternalAddresses::putAddressInternal(uint32_t startIndex, const std::string &address) {
			std::stringstream ss;

			ss << "INSERT INTO " << EA_TABLE_NAME << " (" <<
			   EA_COLUMN_ID << "," <<
			   EA_ADDRESS <<
			   ") VALUES (?, ?);";

			sqlite3_stmt *stmt;
			ParamChecker::checkCondition(!_sqlite->prepare(ss.str(), &stmt, nullptr), Error::SqliteError,
										 "Prepare sql " + ss.str());

			_sqlite->bindInt(stmt, 1, startIndex);
			_sqlite->bindText(stmt, 2, address, nullptr);

			_sqlite->step(stmt);
			_sqlite->finalize(stmt);

			return true;
		}

		bool ExternalAddresses::clearAddresses() {
			return doTransaction([this]() {
				std::stringstream ss;

				ss << "DELETE FROM " << EA_TABLE_NAME << ";";

				ParamChecker::checkCondition(!_sqlite->exec(ss.str(), nullptr, nullptr), Error::SqliteError,
											 "exec sql " + ss.str());
			});
		}

		std::vector<std::string> ExternalAddresses::getAddresses(uint32_t startIndex, uint32_t count) const {
			std::vector<std::string> results;

			doTransaction([startIndex, count, &results, this]() {
				std::string addr;
				std::stringstream ss;
				ss << "SELECT " <<
				   EA_ADDRESS <<
				   " FROM " << EA_TABLE_NAME <<
				   " WHERE " << EA_COLUMN_ID << " >= " << startIndex <<
				   " AND " << EA_COLUMN_ID << " < " << startIndex + count << ";";

				sqlite3_stmt *stmt;
				ParamChecker::checkCondition(!_sqlite->prepare(ss.str(), &stmt, nullptr), Error::SqliteError,
							 "Prepare sql " + ss.str());

				while (SQLITE_ROW == _sqlite->step(stmt)) {
					addr = _sqlite->columnText(stmt, 0);
					results.push_back(addr);
				}

				_sqlite->finalize(stmt);
			});

			return results;
		}

		uint32_t ExternalAddresses::getAvailableAddresses(uint32_t startIndex) const {
			uint32_t results;

			doTransaction([startIndex, &results, this]() {
				std::stringstream ss;
				ss << "SELECT " <<
				   " COUNT(" << EA_ADDRESS << ") AS nums " <<
				   " FROM " << EA_TABLE_NAME <<
				   " WHERE " << EA_COLUMN_ID << " >= " << startIndex << ";";

				sqlite3_stmt *stmt;
				ParamChecker::checkCondition(!_sqlite->prepare(ss.str(), &stmt, nullptr), Error::SqliteError,
											 "Prepare sql " + ss.str());

				while (SQLITE_ROW == _sqlite->step(stmt)) {
					results = (uint32_t) _sqlite->columnInt(stmt, 0);
				}

				_sqlite->finalize(stmt);
			});

			return results;
		}
	}
}