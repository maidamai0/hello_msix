# Hello world for **MSIX**

This is a hello world project demonstrating how to pack a c++ program to a windows **MSIX** package.

The project is highly inspired by [offical document on creating package from source](https://docs.microsoft.com/en-us/windows/msix/package/manual-packaging-root).

## Before you code

Enable **Develop mode** on your windows 10:

```no
Settings -> Update& security -> For developer
```

:bulb: you can check if you have enabled **develop mode** in **powershell**:

```powershell
❯ Get-WindowsDeveloperLicense

ExpirationTime        IsValid
--------------        -------
12/31/9999 8:00:00 AM    True
```

## Minimum steps to package you code

1. Build a cpp executable.
2. Create an `appxmanifest.xml` file
3. Fill the required information in `appxmanifest.xml` file follow the official document
4. Generate the resource files with **PowerSehll** `Appx` module

## How to run this code

* build the executables with cmake
  
  ```cmd
  mkdir build && cd build && cmake ..
  ```

* Install the app follow the next section

## Install/Uninstall

* Install:

  ```powershell
  Add-AppxPackage -Register AppxManifest.xml
  ```

* Get installed package:

  ```powershell
  ❯ Get-AppxPackage -Name Tonghao.Yuan.hello

  Name              : Tonghao.Yuan.hello
  Publisher         : CN=Tonghao, O=Tonghao, L=Shanghai, S=Shanghai, C=China
  Architecture      : X64
  ResourceId        :
  Version           : 1.0.0.0
  PackageFullName   : Tonghao.Yuan.hello_1.0.0.0_x64__nqywa46cgs0va
  InstallLocation   : D:\csd\msix\pack
  IsFramework       : False
  PackageFamilyName : Tonghao.Yuan.hello_nqywa46cgs0va
  PublisherId       : nqywa46cgs0va
  IsResourcePackage : False
  IsBundle          : False
  IsDevelopmentMode : True
  NonRemovable      : False
  IsPartiallyStaged : False
  SignatureKind     : None
  Status            : Ok
  ```

* Uninstall:

  ```powershell
  Remove-AppxPackage -Package "Tonghao.Yuan.hello_nqywa46cgs0va"
  ```
