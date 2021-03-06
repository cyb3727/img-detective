#include "common/CommonInternal.h"

namespace ImgDetective  {
namespace Core {

	void ConvertToSearchResult(const REF imgid_col_t& imgIds, REF SearchResult& result, void* (*memoryAllocFunc)(size_t)) {
		result.arraySize = imgIds.size();
		if (imgIds.size() != 0) {
            result.items = (imgid_t*)memoryAllocFunc(imgIds.size() * sizeof(imgid_t));
			
			size_t resultIndex = 0;
			imgid_col_t::const_iterator it;
			for (it = imgIds.cbegin(); it != imgIds.cend(); ++it) {
				result.items[resultIndex] = *it;
				++resultIndex;
			}
		}
	}

    blob_p_t CreateBlobOfSize(size_t blobSize) {
        blob_p_t blob = new blob_t();
        blob->resize(blobSize);

        return blob;
    }

    void SafeFreeBlob(REF blob_p_t& blob) {
        if (blob != NULL) {
            delete blob;
            blob = NULL;
        }
    }

    char* BlobToCharArray(blob_p_t blob) {
        if (blob != NULL) {
            return blob->data();
        }
        else {
            return NULL;
        }
    }

    void CopyToBlob(void* data, blob_p_t blob) {
        if (data != NULL && blob != NULL) {
            memcpy(blob->data(), data, blob->size());
        }
    }

    bool IsValidImgId(imgid_t imgId) {
        return imgId > 0;
    }
}
}