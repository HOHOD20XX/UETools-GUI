#pragma once
#include "SDK\Engine_classes.hpp"






namespace Unreal
{
	class Engine
	{
	public:
		/**
		* @brief Retrieves the current instance of the Unreal Engine, if one is available.
		* @return A valid pointer to the existing instance; 
		*		  otherwise returns 'nullptr' to indicate that no instance is currently accessible.
		*/
		static SDK::UEngine* Get();
	};




	class GameViewportClient
	{
	public:
		/**
		* @brief Retrieves the current instance of the Game Viewport Client, if one is available.
		* @return A valid pointer to the existing instance; 
		*		  otherwise returns 'nullptr' to indicate that no instance is currently accessible.
		*/
		static SDK::UGameViewportClient* Get();
	};




	class Console
	{
	public:
		/**
		* @brief Retrieves the current instance of the Console, if one is available.
		* @return A valid pointer to the existing instance;
		*		  otherwise returns 'nullptr' to indicate that no instance is currently accessible.
		*/
		static SDK::UConsole* Get();

		/**
		* @brief Constructs a Console and assigns it to the active Game Viewport Client.
		* @param ignorePresence - If set to 'True', a new Console will always be created, even if one already exist.
		* @return 'True' if the console was successfully created and assigned to Game Viewport Client.
		*/
		static bool Construct(const bool& ignorePresence = false);


		/**
		* @brief Outputs a message in to the Console. Multiple overloads for convenience, including Unreal Engine data types.
		* @param std::wstring
		* @param std::string
		* @param int32_t
		* @param uint32_t
		* @param FVector
		* @param FRotator
		* @param UObject*
		* @return 'True' if the value was successfully printed; 'False' otherwise.
		*/
		static bool Print(const std::wstring& string);
		static bool Print(const std::string& string);

		static bool Print(const int32_t& value);
		static bool Print(const uint32_t& value);

		static bool Print(const SDK::FVector& vector);
		static bool Print(const SDK::FRotator& rotator);

		static bool Print(SDK::UObject* objectReference);

		static bool Print();
	};




	class PlayerController
	{
	public:
		static SDK::APlayerController* Get(const int32_t& playerIndex = 0);
	};
};

