#ifndef _FILE_IO_H
#define _FILE_IO_H

#include "Core.h"
#include <string>
#include <vector>

namespace F515_StandardFileIO {
	class FROSTY515_API FileIO {
	public:
		FileIO();
		virtual ~FileIO();

		//const char* ReadFile(const char* path); Reason is explained in FileIO.cpp
		std::string ReadFile(const std::string& path);
		std::string ReadFile(const char* path);

		std::string getFileExtension(const std::string& path);
		std::string getFileExtension(const char* path);

		bool isPathExist(const std::string& path);
		bool isPathExist(const char* path);

		bool isDirectory(const std::string& path);
		bool isDirectory(const char* path);

		bool isFile(const std::string& path);
		bool isFile(const char* path);

		bool isDirectoryEmpty(const char* path);
		bool isDirectoryEmpty(const std::string& path);

		uint64_t fileSizeInBytes(const char* path);
		uint64_t fileSizeInBytes(const std::string& path);

		void WriteFile(const std::string& data, const char* path, bool override = false);
		void WriteFile(const char* data, const char* path, bool override = false);

		void DeleteFile(const std::string& path);
		void DeleteFile(const char* path);

		void CopyFile(const std::string& src, const std::string& dest, bool overrideDest = false);
		void CopyFile(const char* src, const char* dest, bool overrideDest = false);

		#ifdef F515_PLATFORM_WINDOWS

		void MakeDir(const std::string& path);
		void MakeDir(const char* path);

		void RemoveDir(const std::string& path, bool removeTree = false);
		void RemoveDir(const char* path, bool removeTree = false);

		inline void MoveFile(const std::string& src, const std::string& dest, bool overrideDest = false) { CopyFile(src, dest, overrideDest); DeleteFile(dest); };
		inline void MoveFile(const char* src, const char* dest, bool overrideDest = false) { CopyFile(src, dest, overrideDest); DeleteFile(dest); };

		inline void MakeDirectory(const std::string& path) { MakeDir(path); };
		inline void MakeDirectory(const char* path) { MakeDir(path); };

		inline void RemoveDirectory(const std::string& path, bool removeTree = false) { RemoveDir(path, removeTree); };
		inline void RemoveDirectory(const char* path, bool removeTree = false) { RemoveDir(path, removeTree); };

		#else
			#warning Directory systems are windows only
		#endif

		void Log(const char* str);
		void Log(const std::string& str);

		std::vector<std::string> ListDirContents(const char* path);
		std::vector<std::string> ListDirContents(const std::string& path);
	};
}

#endif /* _FILE_IO_H */