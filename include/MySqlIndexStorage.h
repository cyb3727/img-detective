#pragma once

#include "IndexStorage.h"
#include <string>

namespace ImgDetective {
namespace Core {

	CONCRETE SEALED class MySqlIndexStorage : public IndexStorage {
	public:
		class LookupSession : public LookupSessionBase {
		public:
			LookupSession(IFeatureDeserializer* featureDeserializer, unsigned int packetSize);
			virtual bool GetNextPacket(IndexNode::col_p_t& packet);
		private:
			unsigned int packetSize;
			unsigned int curPacketNumber;
		};

		MySqlIndexStorage(IFeatureDeserializer* featureDeserializer, std::string connectionString, unsigned int packetSize);
		virtual LookupSessionBase* StartLookup() const;
	private:
		std::string connectionString;
		unsigned int packetSize;
	};
}
}