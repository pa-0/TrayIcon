`TrayIcon` Project Overview
=========================================================

>_MICROSOFT Basic Class Library_

The Application Wizard has created this TrayIcon application for you. This application not only demonstrates the basic use of Microsoft foundation classes, but also serves as a starting point for writing your applications.

Source Code Files
-----------------

### `TrayIcon.vcxproj`

This is the main project file for a VC++ project generated using the AppWizard. 
- It contains information about the version of Visual C++ that generated the file, as well as information about the platform, configuration, and project features selected using the AppWizard.

### `TrayIcon.vcxproj.filters`

This is a VC++ project filter file generated using the Application Wizard.
- It contains information about the association between project files and filters.
- In the IDE, this association allows files with similar extensions to be displayed in groups under specific nodes.
  - For example, ".cpp" files are associated with the "Source Files" filter.

### `TrayIcon.h`

This is the main header file of the application. It includes other project-specific header files (including Resource.h) and declares the CTrayIconApp application class.

### `TrayIcon.cpp`

This is the main application source file that contains the application class CTrayIconApp.

### `TrayIcon.rc`

This is a list of all Microsoft Windows resources used by the program. 
- It includes (stored in the RES subdirectory):
  - icons,
  - bitmaps, and
  - cursors .
- This file can be edited directly in Microsoft Visual C++.
- Project resources are located in 2052.

### `res\TrayIcon.ico`

This is the icon file used as the application icon. This icon is included in the main resource file TrayIcon.rc.

### `res\TrayIcon.rc2`

This file contains resources that are not editable in Microsoft Visual C++. You should place all resources that are not editable by the resource editor in this file.

/////////////////////////////////////////////////////////////////////////////

Application Wizard creates a dialog class:
------------------------------------------

### `TrayIconDlg.h`, `TrayIconDlg.cpp` - Dialog

These files contain the `CTrayIconDlg` class. This class defines the behavior of the application's main dialog box. The dialog box's template is located in TrayIcon.rc, which can be edited in Microsoft Visual C++.

/////////////////////////////////////////////////////////////////////////////

Other features:
---------------

### ActiveX control

The application includes support for using ActiveX controls.

### Print and print preview support

AppWizard has generated code for handling printing, print setup, and print preview commands by calling member functions in the CView class from the MFC library. 

/////////////////////////////////////////////////////////////////////////////

Other standard documents:
-------------------------

### `StdAfx.h`, `StdAfx.cpp`

These files are used to generate a precompiled header (PCH) file named TrayIcon.pch and a precompiled type file named StdAfx.obj.

### `Resource.h`

This is the standard header file that defines the new resource ID.
- Microsoft Visual C++ reads and updates this file.

### `TrayIcon.manifest`

Application manifest files are used by Windows XP to describe applications.
- Dependencies on specific versions of parallel assemblies. The loader uses this
- Information to load the appropriate assembly from the assembly cache or
- Load private information from the application. Application manifests may be used for redistribution as
- External .manifest files installed in the same folder as the application executable include,
- It may also be included as a resource in the executable file. 

/////////////////////////////////////////////////////////////////////////////

Other notes:
------------

- The Application Wizard uses "`TODO:`" to indicate portions of the source code that should be added or customized.
- If your application uses MFC in shared DLLs, you need to redistribute those MFC DLLs; if your application uses a language that is different from the operating system's current locale, you also need to redistribute the corresponding localized resource `MFC100XXX.DLL`. For more information on these two topics, see the chapter on - Redistributing Visual C++ applications in the MSDN documentation.

/////////////////////////////////////////////////////////////////////////////
