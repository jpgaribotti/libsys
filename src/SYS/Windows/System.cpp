/*
 * File:   System.cpp
 * Author: JoPe
 *
 * Created on 5 de marzo de 2015, 23:49
 */

#include "System.hpp"

#include <cassert>
#include <system_error>
#include <Windows.h>

namespace sys
{
  void CreateFolder(std::string const& path)
  {
    assert(path.size()>0);
    auto result = CreateDirectory(path.c_str(), nullptr);
    if (result != 0)
      return;

    switch (GetLastError())
    {
      case ERROR_PATH_NOT_FOUND:
        CreateFolder(path.substr(0, path.rfind('/')));
        CreateFolder(path.c_str());
        break;
      case ERROR_ALREADY_EXISTS:
        throw std::system_error(EIO, std::system_category(),
            "Folder already exists");
      default:
        throw std::system_error(EIO, std::system_category(),
            "Unknown error creating folder");
    }
  }

  void DuplicateFile(std::string const& i_source, std::string const& i_dest)
  {
    auto result = CopyFile(i_source.c_str(), i_dest.c_str(), TRUE);
    if (result != 0)
      return;

    switch (GetLastError())
    {
      default:
        throw std::system_error(EIO, std::system_category(),
            "Unknown error copying file");
    }
  }

  bool FolderExists(std::string const& i_path)
  {
    auto result = GetFileAttributes(i_path.c_str());
    return result != INVALID_FILE_ATTRIBUTES &&
           (result & FILE_ATTRIBUTE_DIRECTORY) != 0;
  }

  std::string UserDocuments()
  {
    /*PWSTR path = nullptr;
    auto hr = SHGetKnownFolderPath(FOLDERID_Documents, 0, NULL, &path);*/
    // Placeholder until I get Visual Studio running
    return "C:/Users/JoPe/Documents";
  }
}