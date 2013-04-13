#include "core/BindInfo.h"
#include "utils/MemoryUtils.h"
#include "utils/ContractUtils.h"

namespace ImgDetective {
namespace Core {
namespace Db {

    CTOR DbParamBuffer::DbParamBuffer(void* data, size_t length, DbType::Enum dbType) {
        Utils::Contract::Assert(data != NULL || length == 0, "DbParamBuffer ctor: if the data is null the length must be 0 as well");
        Utils::Contract::Assert(length >= 0, "DbParamBuffer ctor: length must be greater or equal 0");

        if (data != NULL) {
            this->data = new char[length];
            memcpy(this->data, data, length);
        }

        this->dataLength = length;
        this->dbType = dbType;
    }

    void* DbParamBuffer::GetDataPtr() const {
        return data;
    }

    size_t DbParamBuffer::GetDataLength() const {
        return dataLength;
    }

    DbType::Enum DbParamBuffer::GetType() const {
        return dbType;
    }

    bool DbParamBuffer::IsNull() const {
        return data == NULL;
    }
}
}
}