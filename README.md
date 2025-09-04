# UETools-GUI
Dumper-7 (SDK) based solution for quick & easy debugging of Unreal Engine powered games. So easy to start with that within 5 minutes you will get it running on any* game given.
> \*Dumper-7 must generate a valid SDK in order for a game to be considered "supported".
> 
> \*UETools-GUI was developed with Unreal Engine 4.27 in mind, so the project can be relatively easily upgraded or downgraded. Certain parts of the code may need to be modified to account for the specifics of your Engine (such as not yet implemented or deprecated variables and functions).
> 
> **P.S:** When working with Unreal Engine 5 based games, consider uncommenting "#define UE5" within the "GUI.h" file.

# Getting Started
1. Download and unpack OR Git Clone the repository;
2. Generate Dumper-7 SDK for the game you want to implement UETools-GUI in;
3. Replace the SDK within `..\SDKs\Dumper7` with your newly generated, game-specific one;
4. Compile `UETools-GUI.dll` and inject it into the running game (using Cheat Engine, Process Hacker, etc.).
> When in game, press the "INS" (Insert) key in order to show or hide the menu.

# Baseline & Environment
```
Unreal Engine: 4.27.2
C++: ISO 20 | C: Legacy MSVC
Windows SDK: "10.0.26100.0"
Build Configuration: Release
```

# Dependencies
### [Dumper-7](https://github.com/Encryqed/Dumper-7) & [ImGui](https://github.com/ocornut/imgui) & [CranchyLib.CPP](https://github.com/Cranch-fur/CranchyLib.CPP)

# Showcase
https://github.com/user-attachments/assets/0ac43152-42a2-4352-9e07-7fcffe0a20e5

### Unreal Engine 4.22.3 — Samurai Jack: Battle Through Time
`Lines of code modified: 2`

<img width="2559" height="1439" alt="UE4.22.3_SamuraiJackBattleThroughTime" src="https://github.com/user-attachments/assets/2488d383-758a-471c-bcbb-3ebdc5131dd3" />

### Unreal Engine 4.27.2 — Lies Of P (DEMO)
`Lines of code modified: 0`

<img width="2559" height="1439" alt="UE4.27.2_LiesOfPDEMO" src="https://github.com/user-attachments/assets/f7251107-497d-4a5a-a3da-6dff1ef71a8a" />

### Unreal Engine 5.4.4 — Project Borealis: Prologue
`Lines of code modified: #define UE5`

<img width="2559" height="1439" alt="UE5.4.4_ProjectBorealisPrologue" src="https://github.com/user-attachments/assets/41a2368d-c85f-4887-befe-9a33421213ce" />

### Unreal Engine 5.5.4 — Hell is Us (DEMO)
`Lines of code modified: #define UE5`

<img width="2559" height="1439" alt="UE5.5.4_HellIsUsDEMO" src="https://github.com/user-attachments/assets/9cfd8a81-6589-49b1-b908-452aeed68297" />

