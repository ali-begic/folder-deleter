# Folder Deleter

The Folder Deleter application simplifies the process of removing folders by automating their deletion across multiple directories. Designed to handle situations where a folder with the same name exists in various locations, including nested subdirectories and hidden folders, this tool allows users to specify a parent directory and efficiently delete all instances of the specified folder. With options to include or exclude hidden folders, this application ensures thorough and flexible folder management, saving time and effort compared to manual deletion.

## Building the Qt Application from Source

To build and run the Folder Deleter application from source, it would be best solution to open the application in [Qt Creator](https://www.qt.io/), then compile it to your liking. But if you want to do it manually, here are the steps you need to follow: 

1. **Clone the Repository:**
   - Ensure you have Git installed on your system.
   - Open your terminal or command prompt and navigate to the directory where you want to clone the repository.
   - Run the following command:
     ```
     git clone https://github.com/ali-begic/folder-deleter
     ```
   - Navigate into the cloned directory:
     ```
     cd folder-deleter
     ```

2. **Install Qt Dependencies:**
   - Ensure you have the necessary Qt libraries, compilers, and build tools installed. Refer to the official Qt documentation for platform-specific instructions:
     - [Qt Documentation for Windows](https://doc.qt.io/qt-6/windows-deployment.html)
     - [Qt Documentation for macOS](https://doc.qt.io/qt-6/macos-deployment.html)
     - [Qt Documentation for Linux](https://doc.qt.io/qt-6/linux-deployment.html)

3. **Configure and Build:**
   - Create a build directory and navigate into it:
     ```
     mkdir build
     cd build
     ```
   - Run `qmake` to generate the Makefile from the `.pro` file:
     ```
     qmake ../src/folderDeleter.pro
     ```
   - Compile the application:
      - On Windows with MSVC:
        ```
        nmake
        ```
      - On Windows with MinGW:
        ```
        mingw32-make
        ```
      - On macOS and Linux:
        ```
        make
        ```

4. **Run Your Application:**
   - After a successful build, the executable will be located in the build directory.
   - Run the application:
     ```
     ./folderDeleter
     ```
   - On Windows, you can find the executable in the release or debug directory depending on your build configuration.

## Additional Notes

- Ensure that you have the correct version of Qt and associated build tools for your platform.
- If you encounter issues, check the Qt and compiler documentation or seek assistance on community forums.
- If the application still does not work properly, try running it as an administrator.

Thank you for your interest in the Folder Deleter application!
