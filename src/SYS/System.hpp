/*
 * File:   System.hpp
 * Author: JoPe
 *
 * Created on 5 de marzo de 2015, 23:49
 */

#ifndef SYSTEM_HPP
#define	SYSTEM_HPP

#include <string>

namespace sys
{
  void CreateFolder(std::string const& i_path);
  void DuplicateFile(std::string const& i_source, std::string const& i_dest);
  bool FolderExists(std::string const& i_path);
  std::string UserDocuments();

}

#endif	/* SYSTEM_HPP */

