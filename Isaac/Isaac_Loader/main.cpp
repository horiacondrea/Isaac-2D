///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                    
//                                                          //  IsaacFramework  //
//                                                         //////////////////////
// 
// Copyright (c) 2014 Horatiu Condrea
// 
// This software is provided 'as-is', without any express or implied warranty. 
// In no event will the authors be held liable for any damages arising from the use of this software.
// 
// Permission is granted to anyone to use this software for any purpose, including commercial applications, 
// and to alter it and redistribute it freely, subject to the following restrictions:
// 
//  1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. a
//     If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
// 
//  2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
// 
//  3. This notice may not be removed or altered from any source distribution.
// 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Copyright @ 2014
Author Horatiu Condrea [ horiacondrea.com ]
Revision | Who      | Date       | Comment
------------------------------------------------------------------------------------------------------------------------------------------
1.0      | hc       | March 2014 | Created
*/
//                             Headers
/////////////////////////////////////////////////////////////////////////////
#include <iostream>
//#include <vld.h>
#include <LibraryUtils.h>
#include <memory>
#include "cxxopts.h"
/////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
  // Load DLL
  std::string lc_szLibraryPath = "";
  std::string lc_szFunctionName = "";

  try
  {
    cxxopts::Options options(argv[0]);

    options.add_options()
      ("b,binary", "Input binary file", cxxopts::value<std::vector<std::string>>())
      ("f,function", "Input function", cxxopts::value<std::string>())
      ;

    options.parse_positional("binary");

    options.parse(argc, argv);

    if (options.count("b"))
    {
      const auto& lc_Path = options["binary"].as<std::vector<std::string>>();
      for (const auto& f : lc_Path)
      {
        lc_szLibraryPath += f + " ";
      }
      lc_szLibraryPath.resize(lc_szLibraryPath.size() - 1);
    }

    if (options.count("f"))
    {
      lc_szFunctionName = options["function"].as<std::string>();
    }
  }
  catch (const cxxopts::OptionException& e)
  {
    std::cout << "Error parsing options: " << e.what() << std::endl;
    std::cout << "1. First argument  -b : the path to the dynamic library that you want to load. Without the extension" << std::endl;
    std::cout << "2. Second argument -f : the name of the entry point function." << std::endl;
    std::cout << "Example : -b Isaac_TryOut -f CreateGame" << std::endl;
    return EXIT_FAILURE;
  }


  if (lc_szLibraryPath == "")
  {
    std::cout << "Library path is invalid" << std::endl;
    return EXIT_FAILURE;
  }

  if (lc_szFunctionName == "")
  {
    std::cout << "Function name is invalid" << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Loading dynamic library : " << lc_szLibraryPath << std::endl;

  auto libUtil = std::make_shared<isaac::LibraryUtils>(lc_szLibraryPath);

  if (false == libUtil->Load())
  {
    std::cout << "Could not load the dynamic library..." << std::endl;
    return EXIT_FAILURE;
  }
  else
  {
    std::cout << "Successfully loaded the dynamic library. " << std::endl;
  }

  std::cout << "Trying to access the function " << lc_szFunctionName << std::endl;

  if (false == libUtil->CallEntryFunction(lc_szFunctionName))
  {
    std::cout << "Could not locate the function" << std::endl;
    return EXIT_FAILURE;
  }
  else
  {
    std::cout << "Successfully located the function" << std::endl;
  }


  std::cout << "Trying to free the dynamic library ... ";

  if (libUtil->Unload())
  {
    std::cout << "Succeeded" << std::endl;
  }
  else
  {
    std::cout << "Faild" << std::endl;
  }

#ifdef DEBUG
  std::cin.get();
#endif

  return EXIT_SUCCESS;
}