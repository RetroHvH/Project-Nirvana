#include <iostream>
#include <Windows.h>
#include <thread>
#include "patterns.h"
#include <string>
#include <filesystem>
#include </Users/BRZ/source/repos/testScript/auth/auth.hpp>
#include "/Users/BRZ/source/repos/testScript/auth/skStr.h"

std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);
const std::string compilation_date = (std::string)skCrypt(__DATE__);
const std::string compilation_time = (std::string)skCrypt(__TIME__);

using namespace KeyAuth;

std::string name = skCrypt("RICARDORUST").decrypt(); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = skCrypt("a6EDXeYgKV").decrypt(); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = skCrypt("008079f27597a8e11a88897076f786b2dffb164650662fdb6f8aaad78a8336b1").decrypt(); // app secret, the blurred text on licenses tab and other tabs
std::string version = skCrypt("1.0").decrypt(); // leave alone unless you've changed version on website
std::string url = skCrypt("https://keyauth.win/api/1.2/").decrypt(); // change if you're self-hosting

api KeyAuthApp(name, ownerid, secret, version, url);

	struct WeaponFlags {
		bool recoil;
		bool AssaultRife;
		bool SemiRifle;
		bool PythonHandgun;
		bool SemiPistol;
		bool Revolver;
		bool CustomSMG;
		bool LR;
	};

bool brecoil = false;
bool bEnabled = false;
bool bTurnedOn = false;
bool Hidden = false;



void mouse_move(int x, int y)
{
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.mouseData = 0;
	input.mi.time = 0;
	input.mi.dx = x;
	input.mi.dy = y;
	input.mi.dwFlags = MOUSEEVENTF_MOVE;
	SendInput(1, &input, sizeof(input));
}

void RecoilControl()
{
	WeaponFlags weaponFlags;
	weaponFlags = { false, false, false, false, false, false, false, false };


	while(true)
	{
		int shotTiming = 0;
		int shakerNum = rand() % 3;
		while (GetAsyncKeyState(1) & 0x8000 && (GetAsyncKeyState(2) & 0x8000 && brecoil))
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
			if (weaponFlags.AssaultRife == 1)
			{
				int fireRate = 134;

				if (shotTiming < 30)
				{
					int valueX = (AssaultRifle::recoilX[shotTiming] * 0.48) + shakerNum;
					int smoothingX = valueX / 5;
					int valueY = (AssaultRifle::recoilY[shotTiming] * 0.48) + shakerNum;	
					int smoothingY = valueY / 5;
					Sleep(3);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}

			if (weaponFlags.SemiRifle == 1)

			{

				int fireRate = 175;
				if (shotTiming < 16)
				{
					int valueX = (SemiRifle::recoilX[shotTiming] * 0.48);
					int smoothingX = valueX / 5;
					int valueY = (SemiRifle::recoilY[shotTiming] * 0.48) + shakerNum;
					int smoothingY = valueY / 5;
					Sleep(1);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}

			if (weaponFlags.PythonHandgun == 1)

			{

				int fireRate = 150;
				if (shotTiming < 6)
				{
					int valueX = (PythonHandgun::recoilX[shotTiming] * 0.48);
					int smoothingX = valueX / 5;
					int valueY = (PythonHandgun::recoilY[shotTiming] * 0.48) + shakerNum;
					int smoothingY = valueY / 5;
					Sleep(3);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}

			if (weaponFlags.CustomSMG == 1)

			{

				int fireRate = 100;
				if (shotTiming < 24)
				{
					int valueX = (CustomSmg::recoilX[shotTiming] * 0.48);
					int smoothingX = valueX / 5;
					int valueY = (CustomSmg::recoilY[shotTiming] * 0.48);
					int smoothingY = valueY / 5;
					Sleep(3);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}

			if (weaponFlags.Revolver == 1)

			{

				int fireRate = 175;
				if (shotTiming < 8)
				{
					int valueX = (Revolver::recoilX[shotTiming] * 0.48);
					int smoothingX = valueX / 5;
					int valueY = (Revolver::recoilY[shotTiming] * 0.48) + shakerNum;
					int smoothingY = valueY / 5;
					Sleep(3);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}


			if (weaponFlags.SemiPistol == 1)

			{

				int fireRate = 150;
				if (shotTiming < 10)
				{
					int valueX = (SemiPistol::recoilX[shotTiming] * 0.48);
					int smoothingX = valueX / 5;
					int valueY = (SemiPistol::recoilY[shotTiming] * 0.48) + shakerNum;
					int smoothingY = valueY / 5;
					Sleep(3);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}
			if (weaponFlags.LR == 1)

			{

				int fireRate = 120;
				if (shotTiming < 30)
				{
					int valueX = (lrRifle::recoilX[shotTiming] * 0.48) + shakerNum;
					int smoothingX = valueX / 5;
					int valueY = (lrRifle ::recoilY[shotTiming] * 0.48) + shakerNum;
					int smoothingY = valueY / 5;
					Sleep(3);


					for (int i = 0; i < 5; i++)
					{
						mouse_move(valueX, valueY);
						Sleep(fireRate / 5);
					}
					shotTiming++;
				}
			}
		}
	}
}

void keyDispatch()
{
	struct WeaponFlags
	{
		bool recoil;
		bool AssaultRifle;
		bool SemiRifle;
		bool PythonHandgun;
		bool SemiPistol;
		bool Revolver;
		bool CustomSMG;
		bool LR;
	};

	WeaponFlags weaponFlags = { false, false, false, false, false, false, false, false };

	struct WeaponType
	{
		int keyCode;
		bool WeaponFlags::* memberPtr;
		const char* name;
	};

	WeaponType weaponTypes[] = {
		{VK_F3, &WeaponFlags::AssaultRifle, "AK"},
		{VK_F4, &WeaponFlags::LR, "LR"},
		{VK_F5, &WeaponFlags::SemiRifle, "SEMI RIFLE"},
		{VK_F6, &WeaponFlags::SemiPistol, "SEMI PISTOL"},
		{VK_F7, &WeaponFlags::CustomSMG, "CUSTOM SMG"},
		{VK_F8, &WeaponFlags::SemiPistol, "P2"},
		{VK_F9, &WeaponFlags::PythonHandgun, "PYTHON"},
		{VK_F10, &WeaponFlags::Revolver, "REVOLVER"},
	};

	for (;;)
	{
		for (const auto& weaponType : weaponTypes)
		{
			if (GetAsyncKeyState(weaponType.keyCode) < 0)
			{
				Beep(650, 500);
				weaponFlags.recoil = !weaponFlags.recoil;
				weaponFlags.*weaponType.memberPtr = !(weaponFlags.*weaponType.memberPtr);
				bTurnedOn = !bTurnedOn;
				std::cout << weaponType.name << " Enabled = " << weaponFlags.*weaponType.memberPtr << "\n";
				Sleep(300);
			}
		}

		if (GetAsyncKeyState(VK_F2) < 0)
		{
			Beep(650, 500);
			brecoil = !brecoil;
			bTurnedOn = !bTurnedOn;
			std::cout << "Script Enabled = " << bTurnedOn << "\n";
			Sleep(300);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(15));
	}
}

int main()
{
	std::string consoleTitle = (std::string)skCrypt("Recurve Private Loader - Last Updated: ") + compilation_date + " " + compilation_time;
	SetConsoleTitleA(consoleTitle.c_str());
	std::cout << skCrypt("\n\n Connecting..");
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	system("CLS");
	std::cout << skCrypt("\n\n Authenticating with Server..");
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	system("CLS");
	KeyAuthApp.init();
	if (!KeyAuthApp.data.success)
	{
		std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
		Sleep(1500);
		exit(0);
	}

		std::string key;

		std::cout << skCrypt("\n Enter license: ");
		std::cin >> key;
		KeyAuthApp.license(key);

		if (!KeyAuthApp.data.success)
		{
			std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
			Sleep(1500);
			exit(0);
		}

		std::cout << skCrypt("\n Last login: ") << tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.lastlogin)));
		std::cout << skCrypt("\n Subscription(s):  Recurve Private Rust");
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));

		std::string recurveRandomTitle = (std::string)skCrypt("RECURVE | DOWNINGS | TY | PIECE");
		SetConsoleTitleA(recurveRandomTitle.c_str());
		system("CLS");

		std::string asciiRecurve = R"(
 /$$$$$$$  /$$$$$$$$  /$$$$$$  /$$   /$$ /$$$$$$$  /$$    /$$ /$$$$$$$$
| $$__  $$| $$_____/ /$$__  $$| $$  | $$| $$__  $$| $$   | $$| $$_____/
| $$  \ $$| $$      | $$  \__/| $$  | $$| $$  \ $$| $$   | $$| $$      
| $$$$$$$/| $$$$$   | $$      | $$  | $$| $$$$$$$/|  $$ / $$/| $$$$$   
| $$__  $$| $$__/   | $$      | $$  | $$| $$__  $$ \  $$ $$/ | $$__/   
| $$  \ $$| $$      | $$    $$| $$  | $$| $$  \ $$  \  $$$/  | $$      
| $$  | $$| $$$$$$$$|  $$$$$$/|  $$$$$$/| $$  | $$   \  $/   | $$$$$$$$
|__/  |__/|________/ \______/  \______/ |__/  |__/    \_/    |________/
)";

		system("COLOR 06");

		std::cout << asciiRecurve;
		std::cout << "[v1.0]              CODED BY: DOWNINGS | DISTRIBUTED BY: PIECE, TY\n\n";

		std::cout << "[F2]  On/Off\n";
		std::cout << "[F3]  AK47\n";
		std::cout << "[F4]  LR\n";
		std::cout << "[F5]  SEMI RIFLE\n";
		std::cout << "[F6]  CUSTOM AND TOMMY\n";
		std::cout << "[F7]  P2\n";
		std::cout << "[F8]  PYTHON\n";
		std::cout << "[F9]  REVOLVER\n\n";

		std::thread(RecoilControl).detach();
		std::thread(keyDispatch).detach();


		for (;;)
			std::this_thread::sleep_for(std::chrono::milliseconds(15));
		return 0;





		for (int i = 0; i < KeyAuthApp.data.subscriptions.size(); i++) {
			auto sub = KeyAuthApp.data.subscriptions.at(i);
			std::cout << skCrypt("\n name: ") << sub.name;
			std::cout << skCrypt(" : expiry: ") << tm_to_readable_time(timet_to_tm(string_to_timet(sub.expiry)));
		

		std::cout << skCrypt("\n\n Closing in five seconds...");
		Sleep(5000);
		exit(0);


}

std::string tm_to_readable_time(tm ctx) {
	char buffer[80];

	strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);

	return std::string(buffer);
}

static std::time_t string_to_timet(std::string timestamp) {
	auto cv = strtol(timestamp.c_str(), NULL, 10); // long

	return (time_t)cv;
}

static std::tm timet_to_tm(time_t timestamp) {
	std::tm context;

	localtime_s(&context, &timestamp);

	return context;
}
