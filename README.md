# UETools-GUI
Dumper-7 (SDK) based solution for quick & easy debugging of Unreal Engine powered games. So easy to start with that within 5 minutes you will get it running on any* game given.
> \*Dumper-7 must generate a valid SDK in order for game to be considered "supported".
> 
> \*UETools-GUI was developed with Unreal Engine 4.27 in mind, so the project can be relatively easily upgraded or downgraded. Certain parts of the code may need to be modified to account for the specifics of your Engine (such as the float → double change in UE5).
> P.S: While working with UE5, consider uncommenting "#define UE5" within "GUI.h" file.

# Getting Started
1) Download & unpack / Git Clone the repository;
2) Generate Dumper-7 SDK for the game you want to implement UETools-GUI in;
3) Replace SDK within "..\SDKs\Dumper7" with your newly generated, game specific one;
4) Compile UETools-GUI Dynamic Link Library and inject it in to the game.
> When in game, use "INS" (Insert) key in order to show or hide the menu.

# Environment & Dependencies
### C++: ISO 20.
### C: Legacy MSVC.
### Windows SDK: "10.0.26100.0".
### Configuration: Release.
### [Dumper-7](https://github.com/Encryqed/Dumper-7)
### [ImGui](https://github.com/ocornut/imgui)
### [CranchyLib.CPP](https://github.com/Cranch-fur/CranchyLib.CPP)

# Screenshots
### Unreal Engine 4.27
<img width="2114" height="1407" alt="Screenshot_DBD_UE4.27" src="https://github.com/user-attachments/assets/17fbaded-6cd7-4cfa-af0d-9c6e2bf3c168" />

### Unreal Engine 5.4.4
> In order for project to compile, a single line of code had to be changed.
<img width="2559" height="1439" alt="Screenshot_PrjBorealis_UE5.4.4" src="https://github.com/user-attachments/assets/b8d02301-3659-46c6-a26e-aa560d8bbea3" />
