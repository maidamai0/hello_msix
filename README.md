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

## Steps

1. Build a cpp executable.
2. Create an `appxmanifest.xml` file
3. Fill the required information in `appxmanifest.xml` file follow the offical document