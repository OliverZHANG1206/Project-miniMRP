# Project-miniERP
The miniERP will use the MS Access Database to do the management base on Qt development.
V0.1.0 Provide protocol to connect MS Access.

## 1. Install Microsoft .NET SDK
If you have already installed, please skip to the next step.

The installation link is shown here: https://dotnet.microsoft.com/en-us/download

This SDK could enable VS2019 to connect database source using ADO.

If it cannot open the MS Access, try following steps:

Open Internet Information Service (IIS) -> Application pool -> Advanced Setting -> Enable 32 bit on Win64 set True.
