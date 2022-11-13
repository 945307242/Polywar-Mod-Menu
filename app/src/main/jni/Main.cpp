int hi = 1;
#if defined(__aarch64__)
bool is64bit = true;
#else
bool is64bit = false;
#endif
#include <list>
#include <vector>
#include <string.h>
#include <cstring>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Offset2String.hpp"
#include "Includes/IgnoreType.hpp"
#include "Includes/Utils.h"
#include "KittyMemory/MemoryPatch.h"
//#include "ByNameModding/BNM.cpp"
////#include "ByNameModding/BNM.hpp"
#include "Hacks/Offsets.h"
#include "Hacks/Features.hpp"
#include "Includes/Vector3.h"
#include "Includes/monostring.h"
#include "Includes/CreateMonoString.h"
#include "Includes/monoarray.h"
#include "Includes/ObscuredTypes.h"

bool menuauthorized = false;
#include "Menu/Setup.h"

//Target lib here
#define targetLibName OBFUSCATE("libil2cpp.so")

#include "Includes/Macros.h"

int hackthreaddone = 0;
bool updatehooksready = false;
std::string test = "";

// Init Custom Functions

Vector3 GetMyPosition();


// Init Hooks

void (*ChatPlayerMessage)(void *instance, monoString * message,bool team);
void (*HideWeapon)(void *instance, bool b);
void (*UseGrenade)(void *instance);
void (*Respawn)(void *instance);
void (*Teleport)(void *instance, Vector3 pos, Vector3 rot);

void(*old_PlayerScript_Update)(void *instance);
void PlayerScript_Update(void *instance) {
    if (instance != NULL) {
        if (updatehooksready) {
            if (Features::Match.isChatSpam) {
                test = "PlayerScript_Update Chat Spam";
                ChatPlayerMessage(instance, CreateMonoString(ChatSpamMessage),false);
            }
            if (Features::Respawning.Button_isRespawn) {
                Respawn(instance);
                Features::Respawning.Button_isRespawn = false;
            }
            if (Features::Grenades.isInfiniteGrenades) {
                SetObscuredInt((uint64_t) instance + Offsets::Fields.InfiniteGrenades, 999);
            }
            if (Features::Movement.Teleport_Button_isTeleport) {
                Teleport(instance,Vector3(float(Features::Movement.Teleport_InputValue_X),float(Features::Movement.Teleport_InputValue_Y),float(Features::Movement.Teleport_InputValue_Z)),Vector3(0.0f, 0.0f, 0.0f));
                Features::Movement.Teleport_Button_isTeleport = false;
            }
        }
    }
    old_PlayerScript_Update(instance);
}

void(*old_PlayerScript_Respawn_Internal)(void *instance, Vector3 RespawnPos, float RespawnRotY,  ignoretype info);
void PlayerScript_Respawn_Internal(void *instance, Vector3 RespawnPos, float RespawnRotY, ignoretype info) {
    if (instance != NULL) {
        if (updatehooksready) {
            if (Features::Respawning.isDisableRespawn) {
                return;
            }
            if (Features::Respawning.isRespawnInPlace) {
                old_PlayerScript_Respawn_Internal(instance,GetMyPosition(), RespawnRotY, info);
                return;
            }
            if (Features::Respawning.CustomRespawnPositon_isCustomRespawnPosition) {
                old_PlayerScript_Respawn_Internal(instance,Vector3(float(Features::Respawning.CustomRespawnPositon_InputValue_X),float(Features::Respawning.CustomRespawnPositon_InputValue_Y),float(Features::Respawning.CustomRespawnPositon_InputValue_X)), RespawnRotY, info);
                return;
            }
        }
    }
    old_PlayerScript_Respawn_Internal(instance, RespawnPos, RespawnRotY, info);
}

void(*old_PlayerScript_Die)(void *instance, int id_killer, int myPoints, bool isHeadshot, short weaponType, short damage);
void PlayerScript_Die(void *instance, int id_killer, int myPoints, bool isHeadshot, short weaponType, short damage) {
    if (instance != NULL) {
        if (updatehooksready) {
            if (Features::Player.isGodmodeV1) {
                return;
            }
        }
    }
    old_PlayerScript_Die(instance, id_killer, myPoints, isHeadshot, weaponType, damage);
}

bool(*old_PlayerScript_get_throwingGrenade)(void *instance);
bool PlayerScript_get_throwingGrenade(void *instance) {
    if (instance != NULL) {
        if (updatehooksready) {
            if (Features::Grenades.isNoGrenadeAnimation) {
                return false;
            }
        }
    }
    old_PlayerScript_get_throwingGrenade(instance);
}

void(*old_WeaponScript_Update)(void *instance);
void WeaponScript_Update(void *instance) {
    if (instance != NULL) {
        if (updatehooksready) {
            if (Features::Weapons.isDamage) {
                *(short *) ((uint64_t) instance + Offsets::Fields.WeaponDamage) = short(Features::Weapons.SeekBar_Damage);
            }
            if (Features::Weapons.isClipSize) {
                *(int *) ((uint64_t) instance + Offsets::Fields.ClipSize) = Features::Weapons.SeekBar_ClipSize;
            }
            if (Features::Weapons.isAccuracy) {
                *(float *) ((uint64_t) instance + Offsets::Fields.Accuracy) = 100.0f;
            }
            if (Features::Weapons.isNoShootDelay) {
                *(bool *) ((uint64_t) instance + Offsets::Fields.ShootDelay) = false;
            }
            if (Features::Weapons.isShootLasers) {
                *(bool *) ((uint64_t) instance + Offsets::Fields.ShootLasers) = true;
            }
            if (Features::Weapons.isSilent) {
                *(bool *) ((uint64_t) instance + Offsets::Fields.Silent) = true;
            }
            if (Features::Weapons.isNoRecoil) {
                *(Vector3 *) ((uint64_t) instance + Offsets::Fields.Recoil) = Vector3(0.0f, 0.0f, 0.0f);
            }
            if (Features::Weapons.isHideWeapon) {
                HideWeapon(instance,false);
            }
            if (Features::Grenades.isGrenadeSpam) {
                UseGrenade(instance);
            }
        }
    }
    old_WeaponScript_Update(instance);
}

bool(*old_WeaponScript_CanShoot)(void *instance);
bool WeaponScript_CanShoot(void *instance) {
    if (instance != NULL) {
        if (updatehooksready) {
            if (Features::Weapons.isRapidFire) {
                return true;
            }
        }
    }
    old_WeaponScript_CanShoot(instance);
}

bool(*old_CharacterController_DetectCollisions)(void *instance);
bool CharacterController_DetectCollisions(void *instance) {
    if (instance != NULL) {
        if (updatehooksready) {
            if (Features::Movement.isNoClip) {
                return false;
            }
        }
    }
    old_CharacterController_DetectCollisions(instance);
}

void(*old_PlayerController_Update)(void *instance);
void PlayerController_Update(void *instance) {
    if (instance != NULL) {
        if (updatehooksready) {
            if (Features::Movement.isInfiniteJump) {
                *(bool *) ((uint64_t) instance + Offsets::Fields.isGrounded) = true;
            }
        }
    }
    old_PlayerController_Update(instance);
}

void(*old_XAds_Play)(void *instance, monostring name, float deltaVideoTime, monostring placement);
void XAds_Play(void *instance, monostring name, float deltaVideoTime, monostring placement) {
    if (instance != NULL) {
        if (updatehooksready) {
            if (Features::Miscellaneous.isNoAds) {
                return;
            }
        }
    }
    old_XAds_Play(instance, name, deltaVideoTime, placement);
}

int(*old_PriceValue_get_price)(void *instance);
int PriceValue_get_price(void *instance) {
    if (instance != NULL) {
        if (updatehooksready) {
            if (Features::Store.isFreeShopping) {
                return 0;
            }
        }
    }
    old_PriceValue_get_price(instance);
}

int(*old_GameParamsScript_get_isVIP)(void *instance);
int GameParamsScript_get_isVIP(void *instance) {
    if (instance != NULL) {
        if (updatehooksready) {
            if (Features::Currency.isVip) {
                return true;
            }
        }
    }
    old_GameParamsScript_get_isVIP(instance);
}

// Custom Functions

Vector3 GetMyPosition() {
    return(Vector3(0.0f,0.0f,0.0f));
}

//Hack thread

// we will run our hacks in a new thread so our while loop doesn't block process main thread
void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));

    //Check if target lib is loaded
    do {
        sleep(1);
    } while (!isLibraryLoaded(targetLibName));

    //Anti-lib rename
    //
    //do {
    //    sleep(1);
    //} while (!isLibraryLoaded("libil2cpp.so"));

    LOGI(OBFUSCATE("%s has been loaded"), (const char *) targetLibName);
    hackthreaddone = 1;

    //Initial Hooks and Patches

    //PlayerScript.Update
    HOOK_LIB("libil2cpp.so", Offset2String(Offsets::Methods.PlayerScript_Update), PlayerScript_Update, old_PlayerScript_Update);

    //PlayerScript.ChatPlayerMessage
    ChatPlayerMessage = (void (*)(void *, monoString *, bool)) getAbsoluteAddress("libil2cpp.so",Offsets::Methods.PlayerScript_ChatPlayerMessage);

    //PlayerScript.Teleport
    Teleport = (void (*)(void *, Vector3, Vector3)) getAbsoluteAddress("libil2cpp.so",  Offsets::Methods.PlayerScript_Teleport);

    //PlayerScript.get_throwingGrenade
    HOOK_LIB("libil2cpp.so", Offset2String(Offsets::Methods.PlayerScript_get_throwingGrenade), PlayerScript_get_throwingGrenade, old_PlayerScript_get_throwingGrenade);

    //PlayerScript.Respawn
    Respawn = (void (*)(void *)) getAbsoluteAddress("libil2cpp.so", Offsets::Methods.PlayerScript_Respawn);

    //PlayerScript._Respawn
    HOOK_LIB("libil2cpp.so", Offset2String(Offsets::Methods.PlayerScript_Respawn_Internal), PlayerScript_Respawn_Internal,
             old_PlayerScript_Respawn_Internal);

    //PlayerScript.Die
    HOOK_LIB("libil2cpp.so", Offset2String(Offsets::Methods.PlayerScript_Die), PlayerScript_Die, old_PlayerScript_Die);

    //WeaponScript.Update
    HOOK_LIB("libil2cpp.so", Offset2String(Offsets::Methods.WeaponScript_Update), WeaponScript_Update, old_WeaponScript_Update);

    //WeaponScript.CanShoot
    HOOK_LIB("libil2cpp.so", Offset2String(Offsets::Methods.WeaponScript_CanShoot), WeaponScript_CanShoot, old_WeaponScript_CanShoot);

    //WeaponScript.HideWeapon
    HideWeapon = (void (*)(void *, bool)) getAbsoluteAddress("libil2cpp.so", Offsets::Methods.WeaponScript_HideWeapon);

    //WeaponScript.UseGrenade
    UseGrenade = (void (*)(void *)) getAbsoluteAddress("libil2cpp.so", Offsets::Methods.WeaponScript_UseGrenade);

    //PlayerController.Update
    HOOK_LIB("libil2cpp.so", Offset2String(Offsets::Methods.PlayerController_Update), PlayerController_Update, old_PlayerController_Update);

    //UnityEngine.CharacterController.get_detectCollisions
    HOOK_LIB("libil2cpp.so", Offset2String(Offsets::Methods.UnityEngine_PlayerController_get_detectColisions), CharacterController_DetectCollisions,
             old_CharacterController_DetectCollisions);

    //XADS.Play
    HOOK_LIB("libil2cpp.so", Offset2String(Offsets::Methods.XAds_Play), XAds_Play, old_XAds_Play);

    //PriceValue.get_price
    HOOK_LIB("libil2cpp.so", Offset2String(Offsets::Methods.PriceValue_get_price), PriceValue_get_price, old_PriceValue_get_price);

    //GameParamsScript.get_isVIP
    HOOK_LIB("libil2cpp.so", Offset2String(Offsets::Methods.GameParamsScript_get_isVIP), GameParamsScript_get_isVIP, old_GameParamsScript_get_isVIP);

    hackthreaddone = 2;
    return NULL;
}

// Do not change or translate the first text unless you know what you are doing
// Assigning feature numbers is optional. Without it, it will automatically count for you, starting from 0
// Assigned feature numbers can be like any numbers 1,3,200,10... instead in order 0,1,2,3,4,5...
// ButtonLink, Category, RichTextView and RichWebView is not counted. They can't have feature number assigned
// Toggle, ButtonOnOff and CheckBox can be switched on by default, if you add True_. Example: CheckBox_True_The Check Box
// To learn HTML, go to this page: https://www.w3schools.com/

jobjectArray GetFeatureList(JNIEnv *env, jobject context) {
    jobjectArray ret;

    const char *features[] = {
            OBFUSCATE("RichTextView_Polywar V1.1 Mod Menu By HorridModz\nDiscord: User123456789#6424"),
            OBFUSCATE("RichTextView_WARNING:\nI do not want to cause too much damage to the game devs or other players. If this mod menu is abused too much, I will disable it so the game is not ruined."),
            OBFUSCATE("Category_Currency"),
            OBFUSCATE("0_Toggle_VIP"),
            OBFUSCATE("Category_Store"),
            OBFUSCATE("1_Toggle_Free Shopping"),
            OBFUSCATE("2_Toggle_Free In-app Purchases"),
            OBFUSCATE("Category_Battle Pass"),
            OBFUSCATE("3_Button_Unlock Premium Battle Pass"),
            OBFUSCATE("4_Button_Reset Battle Pass Rewards"),
            OBFUSCATE("5_Toggle_Infinite Battle Pass Rewards"), //Spam collect battle pass rewards - they never stop letting you collect them
            OBFUSCATE("6_Button_Claim All Battle Pass Rewards"), //Claim all unlocked battle pass rewards
            OBFUSCATE("Collapse_Battle Pass Level"),
            OBFUSCATE("7_CollapseAdd_Button_Level Up Battle Pass"),
            OBFUSCATE("8_CollapseAdd_SeekBar_Battle Pass Level_0_100"),
            OBFUSCATE("9_CollapseAdd_Button_Set Battle Pass Level"),
            OBFUSCATE("Collapse_Battle Pass EXP"),
            OBFUSCATE("10_CollapseAdd_SeekBar_Battle Pass EXP_0_100000"),
            OBFUSCATE("11_CollapseAdd_Button_Set Battle Pass EXP"),
            OBFUSCATE("12_CollapseAdd_Button_Add Battle Pass EXP"),
            OBFUSCATE("13_CollapseAdd_Button_Remove Battle Pass EXP"),
            OBFUSCATE("Category_Items"),
            OBFUSCATE("Collapse_Clothes"),
            OBFUSCATE("Collapse_Skins"),
            OBFUSCATE("Collapse_Weapons"),
            OBFUSCATE("Category_Player"),
            OBFUSCATE("14_Toggle_Godmode V1"), //PlayerScript.Die
            OBFUSCATE("15_Toggle_Infinite Health"),
            OBFUSCATE("16_Toggle_Infinite Armor"),
            OBFUSCATE("Collapse_Regeneration"),
            OBFUSCATE("17_CollapseAdd_Toggle_Health Regen"), //if false set regen to 0
            OBFUSCATE("18_CollapseAdd_SeekBar_Health Regen_0_1000"),
            OBFUSCATE("19_CollapseAdd_Toggle_Armor Regen"), //if false set regen to 0
            OBFUSCATE("20_CollapseAdd_SeekBar_Armor Regen_0_2000"),
            OBFUSCATE("21_CollapseAdd_SeekBar_Regen Interval (Seconds)_0_60"), // PlayerConfig.regenDelay,  PlayerConfig.regenfrequencey
            OBFUSCATE("22_CollapseAdd_SeekBar_Regen Interval (Miliseconds)_0_2200"), // PlayerConfig.regenDelay,  PlayerConfig.regenfrequencey
            OBFUSCATE("23_Button_Heal"),
            OBFUSCATE("24_Toggle_Thorns"), //PlayerScript.ApplyDamage
            OBFUSCATE("25_SeekBar_Thorns Damage_0_1000"), //PlayerScript.ApplyDamage // when enemy hits you they take set amount of damage back
            OBFUSCATE("26_Toggle_Reflect Damage"), //PlayerScript.ApplyDamage // when you are shot, the enemy that shot you takes damage instead of you
            OBFUSCATE("Collapse_Force Field"),
            OBFUSCATE("27_CollapseAdd_SeekBar_Radius_1_1000"),
            OBFUSCATE("28_CollapseAdd_SeekBar_Damage_0_2800"), //PlayerScript.ApplyDamage
            OBFUSCATE("29_CollapseAdd_SeekBar_Heal_0_2900"), //PlayerScript.ApplyDamage
            OBFUSCATE("30_CollapseAdd_CheckBox_Enable Force Field"),
            OBFUSCATE("31_Toggle_Danger Zone Invincibility"),
            OBFUSCATE("32_Button_Switch Team"), //PlayerScript.getTeam
            OBFUSCATE("33_CheckBox_No Team"),
            OBFUSCATE("34_CheckBox_Both Teams"),
            OBFUSCATE("35_Toggle_No Item Cooldown"),
            OBFUSCATE("36_Toggle_Spectator Mode"),
            OBFUSCATE("37_InputText_Name Spoofer"), //PlayerScript.playerName
            OBFUSCATE("Category_Weapons"),
            OBFUSCATE("38_Toggle_Damage"),
            OBFUSCATE("39_SeekBar_Damage_0_1000"),
            OBFUSCATE("40_Toggle_Rapid Fire"),
            OBFUSCATE("41_Toggle_Fire Rate (Not Implemented)"),
            OBFUSCATE("42_SeekBar_Fire Rate (Not Implemented)_1_1000"),
            OBFUSCATE("43_Toggle_Auto Fire"),
            OBFUSCATE("44_Toggle_Ammo"), //bullets, clips
            OBFUSCATE("45_SeekBar_Ammo_1_1000"), //bullets, clips
            OBFUSCATE("46_Toggle_Clip Size"),
            OBFUSCATE("47_SeekBar_Clip Size_1_1000"),
            OBFUSCATE("48_Toggle_Accuracy"),
            OBFUSCATE("49_Toggle_No Shoot Delay"),
            OBFUSCATE("50_Toggle_Shoot Through Walls"),
            OBFUSCATE("51_Toggle_Shoot Lasers"),
            OBFUSCATE("52_Toggle_Silent"),
            OBFUSCATE("53_Toggle_No Recoil"),
            OBFUSCATE("54_Toggle_Hide Weapon"),
            OBFUSCATE("55_Toggle_Scope Zoom"),
            OBFUSCATE("56_SeekBar_Scope Zoom_1_100"),
            OBFUSCATE("Category_Aimbot"),
            OBFUSCATE("57_Toggle_Aimbot"),
            OBFUSCATE("58_Toggle_OP Aim Assist"), //PlayerConfig.autoaimForce
            OBFUSCATE("59_Toggle_Auto Fire"),
            OBFUSCATE("60_Toggle_Silent Aim"),
            OBFUSCATE("61_SeekBar_Silent Aim Radius_1_10000"),
            OBFUSCATE("Category_Kill Players"),
            OBFUSCATE("62_Toggle_Telekill"),
            OBFUSCATE("63_Toggle_Masskill"),
            OBFUSCATE("64_Button_Kill All"),
            OBFUSCATE("Collapse_Spam Kill Delay"),
            OBFUSCATE("65_CollapseAdd_SeekBar_Minutes_0_60"),
            OBFUSCATE("66_CollapseAdd_SeekBar_Seconds_0_60"),
            OBFUSCATE("67_CollapseAdd_SeekBar_Miliseconds_0_1000"),
            OBFUSCATE("68_Toggle_Spam Kill All"),
            OBFUSCATE("69_InputText_Player To Kill (Case Sensitive!)"),
            OBFUSCATE("70_Button_Kill Player"),
            OBFUSCATE("71_Toggle_Spam Kill Player"),
            OBFUSCATE("Category_Grenades"),
            OBFUSCATE("72_Toggle_Infinite Grenades"), //PlayerScript.frags
            OBFUSCATE("73_Toggle_Grenade Spam"),
            OBFUSCATE("74_Toggle_No Grenade Animation"), //PlayerScript.throwingGrenade
            OBFUSCATE("Category_Vision"),
            OBFUSCATE("Collapse_ESP"),
            OBFUSCATE("75_CollapseAdd_Toggle_Player Lines"),
            OBFUSCATE("76_CollapseAdd_Toggle_Player Boxes"),
            OBFUSCATE("77_CollapseAdd_Toggle_Player Health Bars"), //Display health and damage!
            OBFUSCATE("78_CollapseAdd_Toggle_Player List"),
            OBFUSCATE("79_Toggle_Chams"), //See players through walls
            OBFUSCATE("80_Toggle_Xray"), //Don't render walls
            OBFUSCATE("Collapse_Perspective"),
            OBFUSCATE("81_CollapseAdd_CheckBox_First Person"),
            OBFUSCATE("82_CollapseAdd_CheckBox_Third Person"),
            OBFUSCATE("83_Toggle_Custom FOV"),
            OBFUSCATE("84_SeekBar_FOV_1_100"),
            OBFUSCATE("85_Toggle_Disable Fog"), //PlayerScript.fogMode
            OBFUSCATE("Category_Effects"),
            OBFUSCATE("86_Toggle_Anti-Freeze"),
            OBFUSCATE("87_Toggle_Anti Camera Shake"), //PlayerScript.ShakeCamera
            OBFUSCATE("Category_Movement"),
            OBFUSCATE("88_Toggle_Fly"),
            OBFUSCATE("89_Toggle_Infinite Jump"), //PlayerController.CanJump
            OBFUSCATE("90_Toggle_Jump Height"), //PlayerController.jumpForce
            OBFUSCATE("91_SeekBar_Jump Height_0_1000"), //PlayerController.jumpForce
            OBFUSCATE("92_Toggle_Inverted Jump"), //Jumping makes you go down instead of up!
            OBFUSCATE("93_Toggle_Bunny Hop"),
            OBFUSCATE("94_Toggle_Walk Speed"), //PlayerController.walkSpeed
            OBFUSCATE("95_SeekBar_Walk Speed_0_500"), //PlayerController.walkSpeed
            OBFUSCATE("96_Toggle_Run Speed"), //PlayerController.runSpeed
            OBFUSCATE("97_SeekBar_Run Speed_0_500"), //PlayerController.runSpeed
            OBFUSCATE("98_Toggle_Sprint Speed"), //PlayerController.sprintSpeed
            OBFUSCATE("99_SeekBar_Sprint Speed_0_500"), //PlayerController.sprintSpeed
            OBFUSCATE("100_Toggle_Auto Sprint"), //PlayerScript._sprint
            OBFUSCATE("101_Toggle_No Clip"), //CharacterController.DetectCollisions
            OBFUSCATE("Collapse_Gravity"),
            OBFUSCATE("102_CollapseAdd_Toggle_Gravity Strength"),
            OBFUSCATE("103_CollapseAdd_SeekBar_Gravity_0_1000"),
            OBFUSCATE("104_CollapseAdd_Toggle_Inverted Gravity"),
            OBFUSCATE("105_Toggle_Underwater"),
            OBFUSCATE("Collapse_Teleport"),
            OBFUSCATE("106_CollapseAdd_InputValue_X"),
            OBFUSCATE("107_CollapseAdd_InputValue_Y"),
            OBFUSCATE("108_CollapseAdd_InputValue_Z"),
            OBFUSCATE("109_CollapseAdd_Button_Teleport"),
            OBFUSCATE("Category_Respawning"),
            OBFUSCATE("110_Button_Respawn"),
            OBFUSCATE("111_Toggle_Immediate Respawn"), //PlayerScript.autoRespawn,  PlayerConfig.respawnTime
            OBFUSCATE("112_Toggle_Respawn In Place"),
            OBFUSCATE("113_Toggle_Don't Respawn"),
            OBFUSCATE("Collapse_Custom Respawn Positon"),
            OBFUSCATE("114_CollapseAdd_InputValue_X"),
            OBFUSCATE("115_CollapseAdd_InputValue_Y"),
            OBFUSCATE("116_CollapseAdd_InputValue_Z"),
            OBFUSCATE("117_CollapseAdd_CheckBox_Custom Respawn Position"),
            OBFUSCATE("Category_Vehicles"),
            OBFUSCATE("118_Toggle_Vehicle Infinite Health"), //TransportScript.Health or TransportScropt.transportHealth
            OBFUSCATE("119_Toggle_Vehicle Godmode"), //TransportScript.Die
            OBFUSCATE("Collapse_Teleport Vehicle"),
            OBFUSCATE("120_CollapseAdd_InputValue_X"),
            OBFUSCATE("121_CollapseAdd_InputValue_Y"),
            OBFUSCATE("122_CollapseAdd_InputValue_Z"),
            OBFUSCATE("123_CollapseAdd_Button_Teleport"),
            OBFUSCATE("Collapse_Spawn Vehicle"),
            OBFUSCATE("124_CollapseAdd_InputValue_X"),
            OBFUSCATE("125_CollapseAdd_InputValue_Y"),
            OBFUSCATE("126_CollapseAdd_InputValue_Z"),
            OBFUSCATE("127_CollapseAdd_Button_Spawn Vehicle"),
            OBFUSCATE("Category_Score"),
            OBFUSCATE("Collapse_Score"),
            OBFUSCATE("128_CollapseAdd_InputValue_Score"),
            OBFUSCATE("129_CollapseAdd_Button_Set Score"),
            OBFUSCATE("Collapse_Kills"),
            OBFUSCATE("130_CollapseAdd_InputValue_Kills"),
            OBFUSCATE("131_CollapseAdd_Button_Set Kills"),
            OBFUSCATE("Collapse_Killstreak"),
            OBFUSCATE("132_CollapseAdd_InputValue_Killstreak"),
            OBFUSCATE("133_CollapseAdd_Button_Set Killstreak"),
            OBFUSCATE("Category_Bots"),
            OBFUSCATE("134_Toggle_Disable Bots"),
            OBFUSCATE("135_Button_Remove Bots"),
            OBFUSCATE("136_Button_Kill Bots"),
            OBFUSCATE("Collapse_Add Bots"),
            OBFUSCATE("137_CollapseAdd_CheckBox_Blue Team"),
            OBFUSCATE("138_CollapseAdd_CheckBox_Red Team"),
            OBFUSCATE("139_CollapseAdd_InputText_Name"),
            OBFUSCATE("140_CollapseAdd_Button_Add Bot"),
            OBFUSCATE("Category_Match"),
            OBFUSCATE("141_Toggle_Chat Spam"),
            OBFUSCATE("Collapse_Match Time"),
            OBFUSCATE("142_CollapseAdd_InputValue_Hours"),
            OBFUSCATE("143_CollapseAdd_InputValue_Minutes"),
            OBFUSCATE("144_CollapseAdd_InputValue_Seconds"),
            OBFUSCATE("145_CollapseAdd_Button_Set Time"),
            OBFUSCATE("146_CollapseAdd_CheckBox_Freeze Match Tine"),
            OBFUSCATE("Category_Miscellaneous"),
            OBFUSCATE("147_CheckBox_True_Antiban"),
            OBFUSCATE("148_CheckBox_Bypass_Update"), //YandexAppMetricaConfig.AppVersion
            OBFUSCATE("149_CheckBox_True_No Ads"),
            OBFUSCATE("150_CheckBox_60 FPS"),
            OBFUSCATE("Category_About"),
            OBFUSCATE("ButtonLink_Mod Menu Github Page_https://github.com/HorridModz/Polywar-Mod-Menu"),
            OBFUSCATE("Collapse_My Socials"),
            OBFUSCATE("CollapseAdd_RichTextView_Discord: User123456789#6424\nYoutube: HorridModz 2.0\nGithub: HorridModz\nGameguardian: HorridModz\n"),
            OBFUSCATE("CollapseAdd_ButtonLink_Youtube_https://www.youtube.com/channel/UCt17kVvITO-q-zUICdw7hUQ"),
            OBFUSCATE("CollapseAdd_ButtonLink_Github_https://github.com/HorridModz"),
            OBFUSCATE("CollapseAdd_ButtonLink_Gameguardian_https://gameguardian.net/forum/profile/1234241-horridmodz/"),
            OBFUSCATE("Collapse_Credits"),
            OBFUSCATE("CollapseAdd_RichTextView_Thanks to LGL for the mod menu template"),
    };

    //Now you dont have to manually update the number everytime;
    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));
    return (ret);
}

void Changes(JNIEnv *env, jclass clazz, jobject obj,
             jint featNum, jstring featName, jint value,
             jboolean boolean, jstring str) {

    LOGD(OBFUSCATE("Feature name: %d - %s | Value: = %d | Bool: = %d | Text: = %s"), featNum,
         env->GetStringUTFChars(featName, 0), value,
         boolean, str != NULL ? env->GetStringUTFChars(str, 0) : "");

    //BE CAREFUL NOT TO ACCIDENTLY REMOVE break;
    switch (featNum) {
		//Currency

		//VIP
		case 0:
			Features::Currency.Toggle_Vip();
			break;
		//Store

		//Free Shopping
		case 1:
			Features::Store.Toggle_FreeShopping();
			break;
		//Free In-app Purchases
		case 2:
			Features::Store.Toggle_FreeInAppPurchases();
			break;
		//Battle Pass

		//Unlock Premium Battle Pass
		case 3:
			Features::BattlePass.Button_UnlockPremiumBattlePass();
			break;
		//Reset Battle Pass Rewards
		case 4:
			Features::BattlePass.Button_ResetBattlePassRewards();
			break;
		//Infinite Battle Pass Rewards
		case 5:
			Features::BattlePass.Toggle_InfiniteBattlePassRewards();
			break;
		//Claim All Battle Pass Rewards
		case 6:
			Features::BattlePass.Button_ClaimAllBattlePassRewards();
			break;
		//Collapse Battle Pass Level

		//Level Up Battle Pass
		case 7:
			Features::BattlePass.BattlePassLevel_Button_LevelUpBattlePass();
			break;
		//Battle Pass Level
		case 8:
			Features::BattlePass.BattlePassLevel_SetSeekBar_BattlePassLevel(value);
			break;
		//Set Battle Pass Level
		case 9:
			Features::BattlePass.BattlePassLevel_Button_SetBattlePassLevel();
			break;
		//Collapse Battle Pass EXP

		//Battle Pass EXP
		case 10:
			Features::BattlePass.BattlePassExp_SetSeekBar_BattlePassExp(value);
			break;
		//Set Battle Pass EXP
		case 11:
			Features::BattlePass.BattlePassExp_Button_SetBattlePassExp();
			break;
		//Add Battle Pass EXP
		case 12:
			Features::BattlePass.BattlePassExp_Button_AddBattlePassExp();
			break;
		//Remove Battle Pass EXP
		case 13:
			Features::BattlePass.BattlePassExp_Button_RemoveBattlePassExp();
			break;
		//Player

		//Godmode V1
		case 14:
			Features::Player.Toggle_GodmodeV1();
			break;
		//Infinite Health
		case 15:
			Features::Player.Toggle_InfiniteHealth();
			break;
		//Infinite Armor
		case 16:
			Features::Player.Toggle_InfiniteArmor();
			break;
		//Heal
		case 23:
			Features::Player.Button_Heal();
			break;
		//Thorns
		case 24:
			Features::Player.Toggle_Thorns();
			break;
		//Thorns Damage
		case 25:
			Features::Player.SetSeekBar_ThornsDamage(value);
			break;
		//Reflect Damage
		case 26:
			Features::Player.Toggle_ReflectDamage();
			break;
		//Danger Zone Invincibility
		case 31:
			Features::Player.Toggle_DangerZoneInvincibility();
			break;
		//Switch Team
		case 32:
			Features::Player.Button_SwitchTeam();
			break;
		//No Team
		case 33:
			Features::Player.CheckBox_NoTeam();
			break;
		//Both Teams
		case 34:
			Features::Player.CheckBox_BothTeams();
			break;
		//No Item Cooldown
		case 35:
			Features::Player.Toggle_NoItemCooldown();
			break;
		//Spectator Mode
		case 36:
			Features::Player.Toggle_SpectatorMode();
			break;
		//Name Spoofer
		case 37:
			Features::Player.SetInputText_NameSpoofer(std::to_string(value));
			break;
		//Collapse Regeneration

		//Health Regen
		case 17:
			Features::Player.Regeneration_Toggle_HealthRegen();
			break;
		//Health Regen
		case 18:
			Features::Player.Regeneration_SetSeekBar_HealthRegen(value);
			break;
		//Armor Regen
		case 19:
			Features::Player.Regeneration_Toggle_ArmorRegen();
			break;
		//Armor Regen
		case 20:
			Features::Player.Regeneration_SetSeekBar_ArmorRegen(value);
			break;
		//Regen Interval (Seconds)
		case 21:
			Features::Player.Regeneration_SetSeekBar_RegenIntervalSeconds(value);
			break;
		//Regen Interval (Miliseconds)
		case 22:
			Features::Player.Regeneration_SetSeekBar_RegenIntervalMiliseconds(value);
			break;
		//Collapse Force Field

		//Radius
		case 27:
			Features::Player.ForceField_SetSeekBar_Radius(value);
			break;
		//Damage
		case 28:
			Features::Player.ForceField_SetSeekBar_Damage(value);
			break;
		//Heal
		case 29:
			Features::Player.ForceField_SetSeekBar_Heal(value);
			break;
		//Enable Force Field
		case 30:
			Features::Player.ForceField_CheckBox_EnableForceField();
			break;
		//Weapons

		//Damage
		case 38:
			Features::Weapons.Toggle_Damage();
			break;
		//Damage
		case 39:
			Features::Weapons.SetSeekBar_Damage(value);
			break;
		//Rapid Fire
		case 40:
			Features::Weapons.Toggle_RapidFire();
			break;
		//Fire Rate (Not Implemented)
		case 41:
			Features::Weapons.Toggle_FireRateNotImplemented();
			break;
		//Fire Rate (Not Implemented)
		case 42:
			Features::Weapons.SetSeekBar_FireRateNotImplemented(value);
			break;
		//Auto Fire
		case 43:
			Features::Weapons.Toggle_AutoFire();
			break;
		//Ammo
		case 44:
			Features::Weapons.Toggle_Ammo();
			break;
		//Ammo
		case 45:
			Features::Weapons.SetSeekBar_Ammo(value);
			break;
		//Clip Size
		case 46:
			Features::Weapons.Toggle_ClipSize();
			break;
		//Clip Size
		case 47:
			Features::Weapons.SetSeekBar_ClipSize(value);
			break;
		//Accuracy
		case 48:
			Features::Weapons.Toggle_Accuracy();
			break;
		//No Shoot Delay
		case 49:
			Features::Weapons.Toggle_NoShootDelay();
			break;
		//Shoot Through Walls
		case 50:
			Features::Weapons.Toggle_ShootThroughWalls();
			break;
		//Shoot Lasers
		case 51:
			Features::Weapons.Toggle_ShootLasers();
			break;
		//Silent
		case 52:
			Features::Weapons.Toggle_Silent();
			break;
		//No Recoil
		case 53:
			Features::Weapons.Toggle_NoRecoil();
			break;
		//Hide Weapon
		case 54:
			Features::Weapons.Toggle_HideWeapon();
			break;
		//Scope Zoom
		case 55:
			Features::Weapons.Toggle_ScopeZoom();
			break;
		//Scope Zoom
		case 56:
			Features::Weapons.SetSeekBar_ScopeZoom(value);
			break;
		//Aimbot

		//Aimbot
		case 57:
			Features::Aimbot.Toggle_Aimbot();
			break;
		//OP Aim Assist
		case 58:
			Features::Aimbot.Toggle_OpAimAssist();
			break;
		//Auto Fire
		case 59:
			Features::Aimbot.Toggle_AutoFire();
			break;
		//Silent Aim
		case 60:
			Features::Aimbot.Toggle_SilentAim();
			break;
		//Silent Aim Radius
		case 61:
			Features::Aimbot.SetSeekBar_SilentAimRadius(value);
			break;
		//Kill Players

		//Telekill
		case 62:
			Features::KillPlayers.Toggle_Telekill();
			break;
		//Masskill
		case 63:
			Features::KillPlayers.Toggle_Masskill();
			break;
		//Kill All
		case 64:
			Features::KillPlayers.Button_KillAll();
			break;
		//Spam Kill All
		case 68:
			Features::KillPlayers.Toggle_SpamKillAll();
			break;
		//Player To Kill (Case Sensitive!)
		case 69:
			Features::KillPlayers.SetInputText_PlayerToKillCaseSensitive(std::to_string(value));
			break;
		//Kill Player
		case 70:
			Features::KillPlayers.Button_KillPlayer();
			break;
		//Spam Kill Player
		case 71:
			Features::KillPlayers.Toggle_SpamKillPlayer();
			break;
		//Collapse Spam Kill Delay

		//Minutes
		case 65:
			Features::KillPlayers.SpamKillDelay_SetSeekBar_Minutes(value);
			break;
		//Seconds
		case 66:
			Features::KillPlayers.SpamKillDelay_SetSeekBar_Seconds(value);
			break;
		//Miliseconds
		case 67:
			Features::KillPlayers.SpamKillDelay_SetSeekBar_Miliseconds(value);
			break;
		//Grenades

		//Infinite Grenades
		case 72:
			Features::Grenades.Toggle_InfiniteGrenades();
			break;
		//Grenade Spam
		case 73:
			Features::Grenades.Toggle_GrenadeSpam();
			break;
		//No Grenade Animation
		case 74:
			Features::Grenades.Toggle_NoGrenadeAnimation();
			break;
		//Vision
		//Collapse ESP

		//Player Lines
		case 75:
			Features::Vision.Esp_Toggle_PlayerLines();
			break;
		//Player Boxes
		case 76:
			Features::Vision.Esp_Toggle_PlayerBoxes();
			break;
		//Player Health Bars
		case 77:
			Features::Vision.Esp_Toggle_PlayerHealthBars();
			break;
		//Player List
		case 78:
			Features::Vision.Esp_Toggle_PlayerList();
			break;

		//Chams
		case 79:
			Features::Vision.Toggle_Chams();
			break;
		//Xray
		case 80:
			Features::Vision.Toggle_Xray();
			break;
		//Custom FOV
		case 83:
			Features::Vision.Toggle_CustomFov();
			break;
		//FOV
		case 84:
			Features::Vision.SetSeekBar_Fov(value);
			break;
		//Disable Fog
		case 85:
			Features::Vision.Toggle_DisableFog();
			break;
		//Collapse Perspective

		//First Person
		case 81:
			Features::Vision.Perspective_CheckBox_FirstPerson();
			break;
		//Third Person
		case 82:
			Features::Vision.Perspective_CheckBox_ThirdPerson();
			break;
		//Effects

		//Anti-Freeze
		case 86:
			Features::Effects.Toggle_AntiFreeze();
			break;
		//Anti Camera Shake
		case 87:
			Features::Effects.Toggle_AntiCameraShake();
			break;
		//Movement

		//Fly
		case 88:
			Features::Movement.Toggle_Fly();
			break;
		//Infinite Jump
		case 89:
			Features::Movement.Toggle_InfiniteJump();
			break;
		//Jump Height
		case 90:
			Features::Movement.Toggle_JumpHeight();
			break;
		//Jump Height
		case 91:
			Features::Movement.SetSeekBar_JumpHeight(value);
			break;
		//Inverted Jump
		case 92:
			Features::Movement.Toggle_InvertedJump();
			break;
		//Bunny Hop
		case 93:
			Features::Movement.Toggle_BunnyHop();
			break;
		//Walk Speed
		case 94:
			Features::Movement.Toggle_WalkSpeed();
			break;
		//Walk Speed
		case 95:
			Features::Movement.SetSeekBar_WalkSpeed(value);
			break;
		//Run Speed
		case 96:
			Features::Movement.Toggle_RunSpeed();
			break;
		//Run Speed
		case 97:
			Features::Movement.SetSeekBar_RunSpeed(value);
			break;
		//Sprint Speed
		case 98:
			Features::Movement.Toggle_SprintSpeed();
			break;
		//Sprint Speed
		case 99:
			Features::Movement.SetSeekBar_SprintSpeed(value);
			break;
		//Auto Sprint
		case 100:
			Features::Movement.Toggle_AutoSprint();
			break;
		//No Clip
		case 101:
			Features::Movement.Toggle_NoClip();
			break;
		//Underwater
		case 105:
			Features::Movement.Toggle_Underwater();
			break;
		//Collapse Gravity

		//Gravity Strength
		case 102:
			Features::Movement.Gravity_Toggle_GravityStrength();
			break;
		//Gravity
		case 103:
			Features::Movement.Gravity_SetSeekBar_Gravity(value);
			break;
		//Inverted Gravity
		case 104:
			Features::Movement.Gravity_Toggle_InvertedGravity();
			break;
		//Collapse Teleport

		//X
		case 106:
			Features::Movement.Teleport_SetInputValue_X(value);
			break;
		//Y
		case 107:
			Features::Movement.Teleport_SetInputValue_Y(value);
			break;
		//Z
		case 108:
			Features::Movement.Teleport_SetInputValue_Z(value);
			break;
		//Teleport
		case 109:
			Features::Movement.Teleport_Button_Teleport();
			break;
		//Respawning

		//Respawn
		case 110:
			Features::Respawning.Button_Respawn();
			break;
		//Immediate Respawn
		case 111:
			Features::Respawning.Toggle_ImmediateRespawn();
			break;
		//Respawn In Place
		case 112:
			Features::Respawning.Toggle_RespawnInPlace();
			break;
		//Don't Respawn
		case 113:
			Features::Respawning.Toggle_DisableRespawn();
			break;
		//Collapse Custom Respawn Positon

		//X
		case 114:
			Features::Respawning.CustomRespawnPositon_SetInputValue_X(value);
			break;
		//Y
		case 115:
			Features::Respawning.CustomRespawnPositon_SetInputValue_Y(value);
			break;
		//Z
		case 116:
			Features::Respawning.CustomRespawnPositon_SetInputValue_Z(value);
			break;
		//Custom Respawn Position
		case 117:
			Features::Respawning.CustomRespawnPositon_CheckBox_CustomRespawnPosition();
			break;
		//Vehicles

		//Vehicle Infinite Health
		case 118:
			Features::Vehicles.Toggle_VehicleInfiniteHealth();
			break;
		//Vehicle Godmode
		case 119:
			Features::Vehicles.Toggle_VehicleGodmode();
			break;
		//Collapse Teleport Vehicle

		//X
		case 120:
			Features::Vehicles.TeleportVehicle_SetInputValue_X(value);
			break;
		//Y
		case 121:
			Features::Vehicles.TeleportVehicle_SetInputValue_Y(value);
			break;
		//Z
		case 122:
			Features::Vehicles.TeleportVehicle_SetInputValue_Z(value);
			break;
		//Teleport
		case 123:
			Features::Vehicles.TeleportVehicle_Button_Teleport();
			break;
		//Collapse Spawn Vehicle

		//X
		case 124:
			Features::Vehicles.SpawnVehicle_SetInputValue_X(value);
			break;
		//Y
		case 125:
			Features::Vehicles.SpawnVehicle_SetInputValue_Y(value);
			break;
		//Z
		case 126:
			Features::Vehicles.SpawnVehicle_SetInputValue_Z(value);
			break;
		//Spawn Vehicle
		case 127:
			Features::Vehicles.SpawnVehicle_Button_SpawnVehicle();
			break;
		//Score
		//Collapse Score

		//Score
		case 128:
			Features::Score.Score_SetInputValue_Score(value);
			break;
		//Set Score
		case 129:
			Features::Score.Score_Button_SetScore();
			break;
		//Collapse Kills

		//Kills
		case 130:
			Features::Score.Kills_SetInputValue_Kills(value);
			break;
		//Set Kills
		case 131:
			Features::Score.Kills_Button_SetKills();
			break;
		//Collapse Killstreak

		//Killstreak
		case 132:
			Features::Score.Killstreak_SetInputValue_Killstreak(value);
			break;
		//Set Killstreak
		case 133:
			Features::Score.Killstreak_Button_SetKillstreak();
			break;
		//Bots

		//Disable Bots
		case 134:
			Features::Bots.Toggle_DisableBots();
			break;
		//Remove Bots
		case 135:
			Features::Bots.Button_RemoveBots();
			break;
		//Kill Bots
		case 136:
			Features::Bots.Button_KillBots();
			break;
		//Collapse Add Bots

		//Blue Team
		case 137:
			Features::Bots.AddBots_CheckBox_BlueTeam();
			break;
		//Red Team
		case 138:
			Features::Bots.AddBots_CheckBox_RedTeam();
			break;
		//Name
		case 139:
			Features::Bots.AddBots_SetInputText_Name(std::to_string(value));
			break;
		//Add Bot
		case 140:
			Features::Bots.AddBots_Button_AddBot();
			break;
		//Match

		//Chat Spam
		case 141:
			Features::Match.Toggle_ChatSpam();
			break;
		//Collapse Match Time

		//Hours
		case 142:
			Features::Match.MatchTime_SetInputValue_Hours(value);
			break;
		//Minutes
		case 143:
			Features::Match.MatchTime_SetInputValue_Minutes(value);
			break;
		//Seconds
		case 144:
			Features::Match.MatchTime_SetInputValue_Seconds(value);
			break;
		//Set Time
		case 145:
			Features::Match.MatchTime_Button_SetTime();
			break;
		//Freeze Match Tine
		case 146:
			Features::Match.MatchTime_CheckBox_FreezeMatchTine();
			break;
		//Miscellaneous

		//Antiban
		case 147:
			Features::Miscellaneous.CheckBox_Antiban();
			break;
		//Bypass
		case 148:
			Features::Miscellaneous.CheckBox_Bypass();
			break;
		//No Ads
		case 149:
			Features::Miscellaneous.CheckBox_NoAds();
			break;
		//60 FPS
		case 150:
			Features::Miscellaneous.CheckBox_60Fps();
			break;
	}
    updatehooksready = true;
}

__attribute__((constructor))
void lib_main() {
    // Create a new thread so it does not block the main thread, means the game would not freeze
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
}

int RegisterMenu(JNIEnv *env) {
    JNINativeMethod methods[] = {
            {OBFUSCATE("Icon"), OBFUSCATE("()Ljava/lang/String;"), reinterpret_cast<void *>(Icon)},
            {OBFUSCATE("IconWebViewData"),  OBFUSCATE("()Ljava/lang/String;"), reinterpret_cast<void *>(IconWebViewData)},
            {OBFUSCATE("IsGameLibLoaded"),  OBFUSCATE("()Z"), reinterpret_cast<void *>(isGameLibLoaded)},
            {OBFUSCATE("Init"),  OBFUSCATE("(Landroid/content/Context;Landroid/widget/TextView;Landroid/widget/TextView;)V"), reinterpret_cast<void *>(Init)},
            {OBFUSCATE("SettingsList"),  OBFUSCATE("()[Ljava/lang/String;"), reinterpret_cast<void *>(SettingsList)},
            {OBFUSCATE("GetFeatureList"),  OBFUSCATE("()[Ljava/lang/String;"), reinterpret_cast<void *>(GetFeatureList)},
    };

    jclass clazz = env->FindClass(OBFUSCATE("com/android/support/Menu"));
    if (!clazz)
        return JNI_ERR;
    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) != 0)
        return JNI_ERR;
    return JNI_OK;
}

int RegisterPreferences(JNIEnv *env) {
    JNINativeMethod methods[] = {
            {OBFUSCATE("Changes"), OBFUSCATE("(Landroid/content/Context;ILjava/lang/String;IZLjava/lang/String;)V"), reinterpret_cast<void *>(Changes)},
    };
    jclass clazz = env->FindClass(OBFUSCATE("com/android/support/Preferences"));
    if (!clazz)
        return JNI_ERR;
    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) != 0)
        return JNI_ERR;
    return JNI_OK;
}

int RegisterMain(JNIEnv *env) {
    JNINativeMethod methods[] = {
            {OBFUSCATE("CheckOverlayPermission"), OBFUSCATE("(Landroid/content/Context;)V"), reinterpret_cast<void *>(CheckOverlayPermission)},
    };
    jclass clazz = env->FindClass(OBFUSCATE("com/android/support/Main"));
    if (!clazz)
        return JNI_ERR;
    if (env->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0])) != 0)
        return JNI_ERR;

    return JNI_OK;
}

extern "C"
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    vm->GetEnv((void **) &env, JNI_VERSION_1_6);
    if (RegisterMenu(env) != 0)
        return JNI_ERR;
    if (RegisterPreferences(env) != 0)
        return JNI_ERR;
    if (RegisterMain(env) != 0)
        return JNI_ERR;
    return JNI_VERSION_1_6;
}