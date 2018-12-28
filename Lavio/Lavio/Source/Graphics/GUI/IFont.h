// **************************************** Lavio Engine ****************************************
// **************************** Copyright (c) 2017 All Rights Reserved **************************
// ***************************** Landon Kirk (landonaddison@yahoo.com) **************************

#pragma once
#include <string>

namespace Lavio
{
	namespace Graphics
	{
		class IFont
		{
		protected:
			unsigned int mSize = 0;

			std::string mName;
			std::string mFilePath;
		public:
			IFont(unsigned int size, const std::string& name, const std::string& filePath)
				: mSize(size), mName(name), mFilePath(filePath)
			{
				
			}
			virtual ~IFont() = default;
			
			virtual void* GetRawAtlasPointer() const = 0;
			virtual void* GetRawFontPointer() const = 0;
			virtual unsigned int GetID() const = 0;

			virtual const std::string& GetName() const { return mName; }
			virtual const std::string& GetFilename() const { return mFilePath; }
			virtual unsigned int GetSize() const { return mSize; }
		
		public:
			IFont(const IFont &other) = delete;
			IFont& operator=(const IFont& rhs) = delete;
		};
	}
}
