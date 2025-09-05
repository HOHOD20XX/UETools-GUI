# UETools-GUI
Dumper-7 (SDK) based solution for rapid debugging of Unreal Engine powered titles. Designed for a minimal setup experience: you can have it running within 5 minutes from the initial download.

> [!NOTE]
> Title is considered supported only if Dumper-7 successfully generates a valid SDK.

> [!NOTE]
> Solution is targeting Unreal Engine 4.27.2 as the base. That allows it to be upgraded or downgraded with relative ease; however, certain code segments may require adjustment to accommodate engine-specific differences (e.g., deprecated or not-yet-implemented variables and functions).

> [!TIP]
> When targeting Unreal Engine 5 based titles, it's recommended to uncomment `#define UE5` in `GUI.h`. In many cases that action alone would be enough to adapt entirity of solution for newer engine.

> [!CAUTION]
> **Disclaimer:** Solution was developed for general use in Unreal Engine powered titles. The author does not condone cheating, modding, or the manipulation of [online competitive games](https://en.wikipedia.org/wiki/List_of_esports_games). The author bears no responsibility for the specific games or contexts in which the solution is used.

# Dependencies
### [Dumper-7](https://github.com/Encryqed/Dumper-7) & [ImGui](https://github.com/ocornut/imgui) & [CranchyLib.CPP](https://github.com/Cranch-fur/CranchyLib.CPP)

# Baseline & Environment
```
Unreal Engine: 4.27.2
C++: ISO 20 | C: Legacy MSVC
Windows SDK: "10.0.26100.0"
Build Configuration: Release
```

# Getting Started
1. Download and extract the repository, or clone it via Git.
2. Generate a Dumper-7 SDK for the target title.
3. Replace the contents of `..\SDKs\Dumper7` with the newly generated, title-specific SDK.
4. Build `UETools-GUI.dll` and load it into the target title process using an appropriate instrumentation method that complies with the game’s EULA and applicable laws. For the purpose, [Cheat Engine](https://www.cheatengine.org/) and [System Informer](https://systeminformer.sourceforge.io/downloads) can be found applicable tools.

# Shortcut
While in the title, hold Left Shift and press Insert (INS) to toggle the menu.

<img width="1130" height="466" alt="SHIFT + INS" src="https://github.com/user-attachments/assets/bec818c7-a5e4-4d7a-9377-1de69ff494df" />

# Showcase
https://github.com/user-attachments/assets/3bff3c81-3b28-40f1-ba3d-39d9f9793769

<img width="2560" height="1440" alt="UE4.22.3_SamuraiJackBattleThroughTime" src="https://github.com/user-attachments/assets/065fad97-5a15-4ca3-91c6-11db6069e007" />

<img width="2560" height="1440" alt="UE4.27.2_LiesOfPDEMO" src="https://github.com/user-attachments/assets/2d963b6a-e200-486f-9f64-7105ab328e00" />

<img width="2560" height="1440" alt="UE5.5.4_MilitsionerPlaytest" src="https://github.com/user-attachments/assets/5adc3ea3-7819-4791-9797-bd7f7cf063ba" />



