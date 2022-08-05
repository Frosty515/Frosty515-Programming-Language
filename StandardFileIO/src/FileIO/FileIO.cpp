#include "FileIO.h"
#include <fstream>
#include <iostream>
#include <sys/stat.h>

#include <cstdio>
#include <filesystem>
#include <cstring>
#include <string>
#include <sstream>

namespace F515_StandardFileIO {

	FileIO::FileIO() {
		m_Logger.ClearLog();
		m_Logger.info("Frosty515 StandardFileIO initialized!");
	}

	FileIO::~FileIO() {
		
	}

	/* Pointer doesn't work. Error: pointer points to memory allocated on the stack
	const char* FileIO::ReadFile(const char* path) {
		std::string output = "";
		if (isPathExist(path)) {
			std::ifstream stream;
			stream.open(path);
			if (stream.is_open()) {
				std::string line;
				while (std::getline(stream, line)) {
					output = output + line + '\n';
				}
				Log("finished reading");
				stream.close();
			}
			else {
				Log("file failed to open");
			}

		}
		else {
			Log("file doesn't exist");
		}
		return output.c_str();
	}*/

	std::string FileIO::ReadFile(const std::string& path) {
		std::string output = "";
		if (isPathExist(path)) {
			std::ifstream stream;
			stream.open(path);
			if (stream.is_open()) {
				std::string line;
				while (std::getline(stream, line)) {
					output = output + line + '\n';
				}
				Log("finished reading");
				stream.close();
			}
			else {
				Log("file failed to open");
			}

		}
		else {
			Log("file doesn't exist");
		}
		return output;
	}

	std::string FileIO::ReadFile(const char* path) {
		std::string output = "";
		if (isPathExist(path)) {
			std::ifstream stream;
			stream.open(path);
			if (stream.is_open()) {
				std::string line;
				while (std::getline(stream, line)) {
					output = output + line + '\n';
				}
				Log("finished reading");
				stream.close();
			}
			else {
				Log("file failed to open");
			}

		}
		else {
			Log("file doesn't exist");
		}
		return output;
	}

	std::string FileIO::getFileExtension(const std::string& path) {
		std::string in = path;
		std::string output = "";
		size_t length = in.length() - 1;
		for (size_t i = length; i > 0; i--) {
			char c = in[i];
			if (c == '.') {
				break;
			}
			else {
				output = c + output;
			}
		}
		return output;
	}

	std::string FileIO::getFileExtension(const char* path) {
		std::string in = path;
		std::string output = "";
		size_t length = in.length() - 1;
		for (size_t i = length; i > 0; i--) {
			char c = in[i];
			if (c == '.') {
				break;
			}
			else {
				output = c + output;
			}
		}
		return output;
	}

	bool FileIO::isPathExist(const std::string& path) {
		struct stat buffer;
		return (stat(path.c_str(), &buffer) == 0);
	}

	bool FileIO::isPathExist(const char* path) {
		struct stat buffer;
		return (stat(path, &buffer) == 0);
	}

	bool FileIO::isDirectory(const std::string& path) {
		struct stat s;
		if (stat(path.c_str(), &s) == 0) {
			if (s.st_mode & S_IFDIR) return true;
		}
		return false;
	}

	bool FileIO::isDirectory(const char* path) {
		struct stat s;
		if (stat(path, &s) == 0) {
			if (s.st_mode & S_IFDIR) return true;
		}
		return false;
	}

	bool FileIO::isFile(const std::string& path) {
		struct stat s;
		if (stat(path.c_str(), &s) == 0){
			if (s.st_mode & S_IFREG) return true;
		}
		return false;
	}

	bool FileIO::isFile(const char* path) {
		struct stat s;
		if (stat(path, &s) == 0) {
			if (s.st_mode & S_IFREG) return true;
		}
		return false;
	}

	bool FileIO::isDirectoryEmpty(const char* path) {
		namespace fs = std::filesystem;
		if (!isDirectory(path))
			return false;

		fs::directory_iterator end_it;
		fs::directory_iterator it(path);
		if (it == end_it)
			return false;
		else
			return true;
	}

	bool FileIO::isDirectoryEmpty(const std::string& path) {
		namespace fs = std::filesystem;
		if (!isDirectory(path))
			return false;

		fs::directory_iterator end_it;
		fs::directory_iterator it(path);
		if (it == end_it)
			return false;
		else
			return true;
	}

	uint64_t FileIO::fileSizeInBytes(const char* path) {
		struct stat stat_buf;
		int rc = stat(path, &stat_buf);
		return rc == 0 ? stat_buf.st_size : -1;
	}

	uint64_t FileIO::fileSizeInBytes(const std::string& path) {
		struct stat stat_buf;
		int rc = stat(path.c_str(), &stat_buf);
		return rc == 0 ? stat_buf.st_size : -1;
	}

	void FileIO::WriteFile(const std::string& data, const char* path, bool override) {
		if ((!isPathExist(path) && !override) || (isPathExist(path) && override)) {
			std::ofstream stream;
			if (isPathExist(path) && override) {
				DeleteFile(path);
			}
			stream.open(path);
			if (stream.is_open()) {
				stream << data;
				Log("Successfully wrote to file!");
				stream.close();
			}
			else {
				Log("stream failed to open");
			}
		}
		else {
			Log("file already exists");
		}
	}

	void FileIO::WriteFile(const char* data, const char* path, bool override) {
		if ((!isPathExist(path) && !override) || (isPathExist(path) && override)) {
			std::ofstream stream;
			if (isPathExist(path) && override) {
				DeleteFile(path);
			}
			stream.open(path);
			if (stream.is_open()) {
				stream << data;
				Log("Successfully wrote to file!");
				stream.close();
			}
			else {
				Log("stream failed to open");
			}
		}
		else {
			Log("file already exists");
		}
	}

	void FileIO::DeleteFile(const std::string& path) {
		int error = std::remove(path.c_str());
		if (error != 0) {
			std::cout << "error " << error << " occurred while removing file: " << path << std::endl;
		}
	}

	void FileIO::DeleteFile(const char* path) {
		int error = std::remove(path);
		if (error != 0) {
			std::cout << "error " << error << " occurred while removing file: " << path << std::endl;
		}
	}

	void FileIO::CopyFile(const std::string& src, const std::string& dest, bool overrideDest) {
		std::ifstream source(src, std::ios::binary);
		std::ofstream dst(dest, std::ios::binary);

		dst << source.rdbuf();
	}

	void FileIO::CopyFile(const char* src, const char* dest, bool overrideDest) {
		std::ifstream source(src, std::ios::binary);
		std::ofstream dst(dest, std::ios::binary);

		dst << source.rdbuf();
	}

	void FileIO::MakeDir(const std::string& path) {
		uint64_t i = m_OSUtils._MKDIR(path.c_str());
		if (i != 0) {
			std::stringstream ss;
			ss << "Error " << i << " occurred while making directory " << path;
			std::string out = ss.str();
			Log(out);
		}
	}

	void FileIO::MakeDir(const char* path) {
		uint64_t i = m_OSUtils._MKDIR(path);
		if (i != 0) {
			std::stringstream ss;
			ss << "Error " << i << " occurred while making directory " << path;
			std::string out = ss.str();
			Log(out);
		}
	}

	void FileIO::RemoveDir(const std::string& path, bool removeTree) {
		if (!isDirectory(path))
			return;

		if (isDirectoryEmpty(path)) {
			uint64_t i = m_OSUtils._RMDIR(path.c_str());
			if (i != 0) {
				Log(("The following error occurred while removing empty directory: " + i));
			}
		}
		else {
			if (!removeTree) {
				Log("Remove tree is required but not enabled");
				return;
			}
			std::vector<std::string> files = ListDirContents(path);
			for (std::string file : files) {
				if (isFile(file))
					DeleteFile(file);
				else if (isDirectory(file))
					RemoveDir(file, true);
				else
					return;
			}
			uint64_t i = m_OSUtils._RMDIR(path.c_str());
			if (i != 0) {
				Log(("The following error occurred while removing empty directory: " + i));
			}
			
		}
	}

	void FileIO::RemoveDir(const char* path, bool removeTree) {
		if (!isDirectory(path))
			return;

		if (isDirectoryEmpty(path)) {
			uint64_t i = m_OSUtils._RMDIR(path);
			if (i != 0) {
				Log(("The following error occurred while removing empty directory: " + i));
			}
		}
		else {
			if (!removeTree) {
				Log("Remove tree is required but not enabled");
				return;
			}
			std::vector<std::string> files = ListDirContents(path);
			for (std::string file : files) {
				if (isFile(file))
					DeleteFile(file);
				else if (isDirectory(file))
					RemoveDir(file, true);
				else
					return;
			}
			uint64_t i = m_OSUtils._RMDIR(path);
			if (i != 0) {
				Log(("The following error occurred while removing empty directory: " + i));
			}

		}
	}

	void FileIO::Log(const char* str) {
		std::stringstream ss;
		ss << "<Frosty515FileUtils-StandardFileIO> " << str;
		m_Logger.info(ss.str());
	}

	void FileIO::Log(const std::string& str) {
		std::stringstream ss;
		ss << "<Frosty515FileUtils-StandardFileIO> " << str;
		m_Logger.info(ss.str());
	}

	std::vector<std::string> FileIO::ListDirContents(const char* path) {
		std::vector<std::string> data;
		for (const auto& file : std::filesystem::directory_iterator(path))
			data.push_back(file.path().string());
		return data;
	}

	std::vector<std::string> FileIO::ListDirContents(const std::string& path) {
		std::vector<std::string> data;
		for (const auto& file : std::filesystem::directory_iterator(path))
			data.push_back(file.path().string());
		return data;
	}

}