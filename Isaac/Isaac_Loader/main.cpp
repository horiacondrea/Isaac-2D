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
/////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
  // Load DLL

  if (argc == 3)
  {
    std::string lc_szLibraryPath = argv[1];
    std::string lc_szFunctionName = argv[2];

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
    
    if ( false == libUtil->Load())
    //HINSTANCE hGetProcIDDLL = LoadLibrary(lc_szLibraryPath.c_str());
    //if (!hGetProcIDDLL) 
    {
      std::cout << "Could not load the dynamic library..." << std::endl;
      return EXIT_FAILURE;
    }
    else
    {
      std::cout << "Successfully loaded the dynamic library. " << std::endl;
    }

    std::cout <<"Trying to access the function " << lc_szFunctionName << std::endl;

    //f_funci game = (f_funci)GetProcAddress(hGetProcIDDLL, lc_szFunctionName.c_str());
    //if (!game) 
    if (false == libUtil->CallEntryFunction(lc_szFunctionName))
    {
      std::cout << "Could not locate the function" << std::endl;
      return EXIT_FAILURE;
    }
    else
    {
      std::cout << "Successfully located the function" << std::endl;
      //game();
    }


    std::cout << "Trying to free the dynamic library ... ";

    //BOOL res = FreeLibrary(hGetProcIDDLL);
    //if (res)
    if ( libUtil->Unload())
    {
      std::cout << "Succeeded" << std::endl;
    }
    else
    {
      std::cout << "Faild" << std::endl;
    }
  }
  else
  {
    std::cout << "1. First argument  : the path to the dynamic library that you want to load." << std::endl;
    std::cout << "2. Second argument : the name of the entry point function." << std::endl;
  }


#ifdef DEBUG
  std::cin.get();
#endif

  return EXIT_SUCCESS;
}