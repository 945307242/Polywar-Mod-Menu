const char* ChatSpamMessage = "Polywar Mod Menu by HorridModz";

namespace Features {
	struct CurrencyHacks {
		//VIP
		bool isVip = false;
		bool updateToggle_Vip = false;
		bool isToggle_VipFirstCall = true;
		void Toggle_Vip() {
			if (!isToggle_VipFirstCall) {
				isVip = true;
				updateToggle_Vip = true;
			} else {
				isToggle_VipFirstCall = false;
			}
		}
	};
	CurrencyHacks Currency;

	struct StoreHacks {
		//Free Shopping
		bool isFreeShopping = false;
		bool updateToggle_FreeShopping = false;
		bool isToggle_FreeShoppingFirstCall = true;
		void Toggle_FreeShopping() {
			if (!isToggle_FreeShoppingFirstCall) {
				isFreeShopping = true;
				updateToggle_FreeShopping = true;
			} else {
				isToggle_FreeShoppingFirstCall = false;
			}
		}
		//Free In-app Purchases
		bool isFreeInAppPurchases = false;
		bool updateToggle_FreeInAppPurchases = false;
		bool isToggle_FreeInAppPurchasesFirstCall = true;
		void Toggle_FreeInAppPurchases() {
			if (!isToggle_FreeInAppPurchasesFirstCall) {
				isFreeInAppPurchases = true;
				updateToggle_FreeInAppPurchases = true;
			} else {
				isToggle_FreeInAppPurchasesFirstCall = false;
			}
		}
	};
	StoreHacks Store;

	struct BattlePassHacks {
		//Unlock Premium Battle Pass
		bool Button_isUnlockPremiumBattlePass = false;
		bool updateButton_UnlockPremiumBattlePass = false;
		bool isButton_UnlockPremiumBattlePassFirstCall = true;
		void Button_UnlockPremiumBattlePass() {
			if (!isButton_UnlockPremiumBattlePassFirstCall) {
				Button_isUnlockPremiumBattlePass = true;
				updateButton_UnlockPremiumBattlePass = true;
			} else {
				isButton_UnlockPremiumBattlePassFirstCall = false;
			}
		}
		//Reset Battle Pass Rewards
		bool Button_isResetBattlePassRewards = false;
		bool updateButton_ResetBattlePassRewards = false;
		bool isButton_ResetBattlePassRewardsFirstCall = true;
		void Button_ResetBattlePassRewards() {
			if (!isButton_ResetBattlePassRewardsFirstCall) {
				Button_isResetBattlePassRewards = true;
				updateButton_ResetBattlePassRewards = true;
			} else {
				isButton_ResetBattlePassRewardsFirstCall = false;
			}
		}
		//Infinite Battle Pass Rewards
		bool isInfiniteBattlePassRewards = false;
		bool updateToggle_InfiniteBattlePassRewards = false;
		bool isToggle_InfiniteBattlePassRewardsFirstCall = true;
		void Toggle_InfiniteBattlePassRewards() {
			if (!isToggle_InfiniteBattlePassRewardsFirstCall) {
				isInfiniteBattlePassRewards = true;
				updateToggle_InfiniteBattlePassRewards = true;
			} else {
				isToggle_InfiniteBattlePassRewardsFirstCall = false;
			}
		}
		//Claim All Battle Pass Rewards
		bool Button_isClaimAllBattlePassRewards = false;
		bool updateButton_ClaimAllBattlePassRewards = false;
		bool isButton_ClaimAllBattlePassRewardsFirstCall = true;
		void Button_ClaimAllBattlePassRewards() {
			if (!isButton_ClaimAllBattlePassRewardsFirstCall) {
				Button_isClaimAllBattlePassRewards = true;
				updateButton_ClaimAllBattlePassRewards = true;
			} else {
				isButton_ClaimAllBattlePassRewardsFirstCall = false;
			}
		}

		//Collapse Battle Pass Level
		//Level Up Battle Pass
		bool BattlePassLevel_Button_isLevelUpBattlePass = false;
		bool updateBattlePassLevel_Button_LevelUpBattlePass = false;
		bool isBattlePassLevel_Button_LevelUpBattlePassFirstCall = true;
		void BattlePassLevel_Button_LevelUpBattlePass() {
			if (!isBattlePassLevel_Button_LevelUpBattlePassFirstCall) {
				BattlePassLevel_Button_isLevelUpBattlePass = true;
				updateBattlePassLevel_Button_LevelUpBattlePass = true;
			} else {
				isBattlePassLevel_Button_LevelUpBattlePassFirstCall = false;
			}
		}
		//Battle Pass Level
		int BattlePassLevel_SeekBar_BattlePassLevel = 1;
		bool updateBattlePassLevel_SeekBar_BattlePassLevel = false;
		bool isBattlePassLevel_SeekBar_BattlePassLevelFirstCall = true;
		void BattlePassLevel_SetSeekBar_BattlePassLevel(int value) {
			if (!isBattlePassLevel_SeekBar_BattlePassLevelFirstCall) {
				BattlePassLevel_SeekBar_BattlePassLevel = value;
				updateBattlePassLevel_SeekBar_BattlePassLevel = true;
		} else {
				isBattlePassLevel_SeekBar_BattlePassLevelFirstCall = false;
			}
		}
		//Set Battle Pass Level
		bool BattlePassLevel_Button_isSetBattlePassLevel = false;
		bool updateBattlePassLevel_Button_SetBattlePassLevel = false;
		bool isBattlePassLevel_Button_SetBattlePassLevelFirstCall = true;
		void BattlePassLevel_Button_SetBattlePassLevel() {
			if (!isBattlePassLevel_Button_SetBattlePassLevelFirstCall) {
				BattlePassLevel_Button_isSetBattlePassLevel = true;
				updateBattlePassLevel_Button_SetBattlePassLevel = true;
			} else {
				isBattlePassLevel_Button_SetBattlePassLevelFirstCall = false;
			}
		}

		//Collapse Battle Pass EXP
		//Battle Pass EXP
		int BattlePassExp_SeekBar_BattlePassExp = 1;
		bool updateBattlePassExp_SeekBar_BattlePassExp = false;
		bool isBattlePassExp_SeekBar_BattlePassExpFirstCall = true;
		void BattlePassExp_SetSeekBar_BattlePassExp(int value) {
			if (!isBattlePassExp_SeekBar_BattlePassExpFirstCall) {
				BattlePassExp_SeekBar_BattlePassExp = value;
				updateBattlePassExp_SeekBar_BattlePassExp = true;
		} else {
				isBattlePassExp_SeekBar_BattlePassExpFirstCall = false;
			}
		}
		//Set Battle Pass EXP
		bool BattlePassExp_Button_isSetBattlePassExp = false;
		bool updateBattlePassExp_Button_SetBattlePassExp = false;
		bool isBattlePassExp_Button_SetBattlePassExpFirstCall = true;
		void BattlePassExp_Button_SetBattlePassExp() {
			if (!isBattlePassExp_Button_SetBattlePassExpFirstCall) {
				BattlePassExp_Button_isSetBattlePassExp = true;
				updateBattlePassExp_Button_SetBattlePassExp = true;
			} else {
				isBattlePassExp_Button_SetBattlePassExpFirstCall = false;
			}
		}
		//Add Battle Pass EXP
		bool BattlePassExp_Button_isAddBattlePassExp = false;
		bool updateBattlePassExp_Button_AddBattlePassExp = false;
		bool isBattlePassExp_Button_AddBattlePassExpFirstCall = true;
		void BattlePassExp_Button_AddBattlePassExp() {
			if (!isBattlePassExp_Button_AddBattlePassExpFirstCall) {
				BattlePassExp_Button_isAddBattlePassExp = true;
				updateBattlePassExp_Button_AddBattlePassExp = true;
			} else {
				isBattlePassExp_Button_AddBattlePassExpFirstCall = false;
			}
		}
		//Remove Battle Pass EXP
		bool BattlePassExp_Button_isRemoveBattlePassExp = false;
		bool updateBattlePassExp_Button_RemoveBattlePassExp = false;
		bool isBattlePassExp_Button_RemoveBattlePassExpFirstCall = true;
		void BattlePassExp_Button_RemoveBattlePassExp() {
			if (!isBattlePassExp_Button_RemoveBattlePassExpFirstCall) {
				BattlePassExp_Button_isRemoveBattlePassExp = true;
				updateBattlePassExp_Button_RemoveBattlePassExp = true;
			} else {
				isBattlePassExp_Button_RemoveBattlePassExpFirstCall = false;
			}
		}
	};
	BattlePassHacks BattlePass;

	struct PlayerHacks {
		//Godmode V1
		bool isGodmodeV1 = false;
		bool updateToggle_GodmodeV1 = false;
		bool isToggle_GodmodeV1FirstCall = true;
		void Toggle_GodmodeV1() {
			if (!isToggle_GodmodeV1FirstCall) {
				isGodmodeV1 = true;
				updateToggle_GodmodeV1 = true;
			} else {
				isToggle_GodmodeV1FirstCall = false;
			}
		}
		//Infinite Health
		bool isInfiniteHealth = false;
		bool updateToggle_InfiniteHealth = false;
		bool isToggle_InfiniteHealthFirstCall = true;
		void Toggle_InfiniteHealth() {
			if (!isToggle_InfiniteHealthFirstCall) {
				isInfiniteHealth = true;
				updateToggle_InfiniteHealth = true;
			} else {
				isToggle_InfiniteHealthFirstCall = false;
			}
		}
		//Infinite Armor
		bool isInfiniteArmor = false;
		bool updateToggle_InfiniteArmor = false;
		bool isToggle_InfiniteArmorFirstCall = true;
		void Toggle_InfiniteArmor() {
			if (!isToggle_InfiniteArmorFirstCall) {
				isInfiniteArmor = true;
				updateToggle_InfiniteArmor = true;
			} else {
				isToggle_InfiniteArmorFirstCall = false;
			}
		}
		//Heal
		bool Button_isHeal = false;
		bool updateButton_Heal = false;
		bool isButton_HealFirstCall = true;
		void Button_Heal() {
			if (!isButton_HealFirstCall) {
				Button_isHeal = true;
				updateButton_Heal = true;
			} else {
				isButton_HealFirstCall = false;
			}
		}
		//Thorns
		bool isThorns = false;
		bool updateToggle_Thorns = false;
		bool isToggle_ThornsFirstCall = true;
		void Toggle_Thorns() {
			if (!isToggle_ThornsFirstCall) {
				isThorns = true;
				updateToggle_Thorns = true;
			} else {
				isToggle_ThornsFirstCall = false;
			}
		}
		//Thorns Damage
		int SeekBar_ThornsDamage = 1;
		bool updateSeekBar_ThornsDamage = false;
		bool isSeekBar_ThornsDamageFirstCall = true;
		void SetSeekBar_ThornsDamage(int value) {
			if (!isSeekBar_ThornsDamageFirstCall) {
				SeekBar_ThornsDamage = value;
				updateSeekBar_ThornsDamage = true;
		} else {
				isSeekBar_ThornsDamageFirstCall = false;
			}
		}
		//Reflect Damage
		bool isReflectDamage = false;
		bool updateToggle_ReflectDamage = false;
		bool isToggle_ReflectDamageFirstCall = true;
		void Toggle_ReflectDamage() {
			if (!isToggle_ReflectDamageFirstCall) {
				isReflectDamage = true;
				updateToggle_ReflectDamage = true;
			} else {
				isToggle_ReflectDamageFirstCall = false;
			}
		}
		//Danger Zone Invincibility
		bool isDangerZoneInvincibility = false;
		bool updateToggle_DangerZoneInvincibility = false;
		bool isToggle_DangerZoneInvincibilityFirstCall = true;
		void Toggle_DangerZoneInvincibility() {
			if (!isToggle_DangerZoneInvincibilityFirstCall) {
				isDangerZoneInvincibility = true;
				updateToggle_DangerZoneInvincibility = true;
			} else {
				isToggle_DangerZoneInvincibilityFirstCall = false;
			}
		}
		//Switch Team
		bool Button_isSwitchTeam = false;
		bool updateButton_SwitchTeam = false;
		bool isButton_SwitchTeamFirstCall = true;
		void Button_SwitchTeam() {
			if (!isButton_SwitchTeamFirstCall) {
				Button_isSwitchTeam = true;
				updateButton_SwitchTeam = true;
			} else {
				isButton_SwitchTeamFirstCall = false;
			}
		}
		//No Team
		bool isNoTeam = false;
		bool updateCheckBox_NoTeam = false;
		bool isCheckBox_NoTeamFirstCall = true;
		void CheckBox_NoTeam() {
			if (!isCheckBox_NoTeamFirstCall) {
				isNoTeam = true;
				updateCheckBox_NoTeam = true;
			} else {
				isCheckBox_NoTeamFirstCall = false;
			}
		}
		//Both Teams
		bool isBothTeams = false;
		bool updateCheckBox_BothTeams = false;
		bool isCheckBox_BothTeamsFirstCall = true;
		void CheckBox_BothTeams() {
			if (!isCheckBox_BothTeamsFirstCall) {
				isBothTeams = true;
				updateCheckBox_BothTeams = true;
			} else {
				isCheckBox_BothTeamsFirstCall = false;
			}
		}
		//No Item Cooldown
		bool isNoItemCooldown = false;
		bool updateToggle_NoItemCooldown = false;
		bool isToggle_NoItemCooldownFirstCall = true;
		void Toggle_NoItemCooldown() {
			if (!isToggle_NoItemCooldownFirstCall) {
				isNoItemCooldown = true;
				updateToggle_NoItemCooldown = true;
			} else {
				isToggle_NoItemCooldownFirstCall = false;
			}
		}
		//Spectator Mode
		bool isSpectatorMode = false;
		bool updateToggle_SpectatorMode = false;
		bool isToggle_SpectatorModeFirstCall = true;
		void Toggle_SpectatorMode() {
			if (!isToggle_SpectatorModeFirstCall) {
				isSpectatorMode = true;
				updateToggle_SpectatorMode = true;
			} else {
				isToggle_SpectatorModeFirstCall = false;
			}
		}
		//Name Spoofer
		std::string InputText_NameSpoofer = "Default";
		bool updateInputText_NameSpoofer = false;
		bool isInputText_NameSpooferFirstCall = true;
		void SetInputText_NameSpoofer(std::string value) {
			if (!isInputText_NameSpooferFirstCall) {
				InputText_NameSpoofer = value;
				updateInputText_NameSpoofer = true;
		} else {
				isInputText_NameSpooferFirstCall = false;
			}
		}

		//Collapse Regeneration
		//Health Regen
		bool Regeneration_isHealthRegen = false;
		bool updateRegeneration_Toggle_HealthRegen = false;
		bool isRegeneration_Toggle_HealthRegenFirstCall = true;
		void Regeneration_Toggle_HealthRegen() {
			if (!isRegeneration_Toggle_HealthRegenFirstCall) {
				Regeneration_isHealthRegen = true;
				updateRegeneration_Toggle_HealthRegen = true;
			} else {
				isRegeneration_Toggle_HealthRegenFirstCall = false;
			}
		}
		//Health Regen
		int Regeneration_SeekBar_HealthRegen = 1;
		bool updateRegeneration_SeekBar_HealthRegen = false;
		bool isRegeneration_SeekBar_HealthRegenFirstCall = true;
		void Regeneration_SetSeekBar_HealthRegen(int value) {
			if (!isRegeneration_SeekBar_HealthRegenFirstCall) {
				Regeneration_SeekBar_HealthRegen = value;
				updateRegeneration_SeekBar_HealthRegen = true;
		} else {
				isRegeneration_SeekBar_HealthRegenFirstCall = false;
			}
		}
		//Armor Regen
		bool Regeneration_isArmorRegen = false;
		bool updateRegeneration_Toggle_ArmorRegen = false;
		bool isRegeneration_Toggle_ArmorRegenFirstCall = true;
		void Regeneration_Toggle_ArmorRegen() {
			if (!isRegeneration_Toggle_ArmorRegenFirstCall) {
				Regeneration_isArmorRegen = true;
				updateRegeneration_Toggle_ArmorRegen = true;
			} else {
				isRegeneration_Toggle_ArmorRegenFirstCall = false;
			}
		}
		//Armor Regen
		int Regeneration_SeekBar_ArmorRegen = 1;
		bool updateRegeneration_SeekBar_ArmorRegen = false;
		bool isRegeneration_SeekBar_ArmorRegenFirstCall = true;
		void Regeneration_SetSeekBar_ArmorRegen(int value) {
			if (!isRegeneration_SeekBar_ArmorRegenFirstCall) {
				Regeneration_SeekBar_ArmorRegen = value;
				updateRegeneration_SeekBar_ArmorRegen = true;
		} else {
				isRegeneration_SeekBar_ArmorRegenFirstCall = false;
			}
		}
		//Regen Interval (Seconds)
		int Regeneration_SeekBar_RegenIntervalSeconds = 1;
		bool updateRegeneration_SeekBar_RegenIntervalSeconds = false;
		bool isRegeneration_SeekBar_RegenIntervalSecondsFirstCall = true;
		void Regeneration_SetSeekBar_RegenIntervalSeconds(int value) {
			if (!isRegeneration_SeekBar_RegenIntervalSecondsFirstCall) {
				Regeneration_SeekBar_RegenIntervalSeconds = value;
				updateRegeneration_SeekBar_RegenIntervalSeconds = true;
		} else {
				isRegeneration_SeekBar_RegenIntervalSecondsFirstCall = false;
			}
		}
		//Regen Interval (Miliseconds)
		int Regeneration_SeekBar_RegenIntervalMiliseconds = 1;
		bool updateRegeneration_SeekBar_RegenIntervalMiliseconds = false;
		bool isRegeneration_SeekBar_RegenIntervalMilisecondsFirstCall = true;
		void Regeneration_SetSeekBar_RegenIntervalMiliseconds(int value) {
			if (!isRegeneration_SeekBar_RegenIntervalMilisecondsFirstCall) {
				Regeneration_SeekBar_RegenIntervalMiliseconds = value;
				updateRegeneration_SeekBar_RegenIntervalMiliseconds = true;
		} else {
				isRegeneration_SeekBar_RegenIntervalMilisecondsFirstCall = false;
			}
		}

		//Collapse Force Field
		//Radius
		int ForceField_SeekBar_Radius = 1;
		bool updateForceField_SeekBar_Radius = false;
		bool isForceField_SeekBar_RadiusFirstCall = true;
		void ForceField_SetSeekBar_Radius(int value) {
			if (!isForceField_SeekBar_RadiusFirstCall) {
				ForceField_SeekBar_Radius = value;
				updateForceField_SeekBar_Radius = true;
		} else {
				isForceField_SeekBar_RadiusFirstCall = false;
			}
		}
		//Damage
		int ForceField_SeekBar_Damage = 1;
		bool updateForceField_SeekBar_Damage = false;
		bool isForceField_SeekBar_DamageFirstCall = true;
		void ForceField_SetSeekBar_Damage(int value) {
			if (!isForceField_SeekBar_DamageFirstCall) {
				ForceField_SeekBar_Damage = value;
				updateForceField_SeekBar_Damage = true;
		} else {
				isForceField_SeekBar_DamageFirstCall = false;
			}
		}
		//Heal
		int ForceField_SeekBar_Heal = 1;
		bool updateForceField_SeekBar_Heal = false;
		bool isForceField_SeekBar_HealFirstCall = true;
		void ForceField_SetSeekBar_Heal(int value) {
			if (!isForceField_SeekBar_HealFirstCall) {
				ForceField_SeekBar_Heal = value;
				updateForceField_SeekBar_Heal = true;
		} else {
				isForceField_SeekBar_HealFirstCall = false;
			}
		}
		//Enable Force Field
		bool ForceField_isEnableForceField = false;
		bool updateForceField_CheckBox_EnableForceField = false;
		bool isForceField_CheckBox_EnableForceFieldFirstCall = true;
		void ForceField_CheckBox_EnableForceField() {
			if (!isForceField_CheckBox_EnableForceFieldFirstCall) {
				ForceField_isEnableForceField = true;
				updateForceField_CheckBox_EnableForceField = true;
			} else {
				isForceField_CheckBox_EnableForceFieldFirstCall = false;
			}
		}
	};
	PlayerHacks Player;

	struct WeaponsHacks {
		//Damage
		bool isDamage = false;
		bool updateToggle_Damage = false;
		bool isToggle_DamageFirstCall = true;
		void Toggle_Damage() {
			if (!isToggle_DamageFirstCall) {
				isDamage = true;
				updateToggle_Damage = true;
			} else {
				isToggle_DamageFirstCall = false;
			}
		}
		//Damage
		int SeekBar_Damage = 1;
		bool updateSeekBar_Damage = false;
		bool isSeekBar_DamageFirstCall = true;
		void SetSeekBar_Damage(int value) {
			if (!isSeekBar_DamageFirstCall) {
				SeekBar_Damage = value;
				updateSeekBar_Damage = true;
		} else {
				isSeekBar_DamageFirstCall = false;
			}
		}
		//Rapid Fire
		bool isRapidFire = false;
		bool updateToggle_RapidFire = false;
		bool isToggle_RapidFireFirstCall = true;
		void Toggle_RapidFire() {
			if (!isToggle_RapidFireFirstCall) {
				isRapidFire = true;
				updateToggle_RapidFire = true;
			} else {
				isToggle_RapidFireFirstCall = false;
			}
		}
		//Fire Rate (Not Implemented)
		bool isFireRateNotImplemented = false;
		bool updateToggle_FireRateNotImplemented = false;
		bool isToggle_FireRateNotImplementedFirstCall = true;
		void Toggle_FireRateNotImplemented() {
			if (!isToggle_FireRateNotImplementedFirstCall) {
				isFireRateNotImplemented = true;
				updateToggle_FireRateNotImplemented = true;
			} else {
				isToggle_FireRateNotImplementedFirstCall = false;
			}
		}
		//Fire Rate (Not Implemented)
		int SeekBar_FireRateNotImplemented = 1;
		bool updateSeekBar_FireRateNotImplemented = false;
		bool isSeekBar_FireRateNotImplementedFirstCall = true;
		void SetSeekBar_FireRateNotImplemented(int value) {
			if (!isSeekBar_FireRateNotImplementedFirstCall) {
				SeekBar_FireRateNotImplemented = value;
				updateSeekBar_FireRateNotImplemented = true;
		} else {
				isSeekBar_FireRateNotImplementedFirstCall = false;
			}
		}
		//Auto Fire
		bool isAutoFire = false;
		bool updateToggle_AutoFire = false;
		bool isToggle_AutoFireFirstCall = true;
		void Toggle_AutoFire() {
			if (!isToggle_AutoFireFirstCall) {
				isAutoFire = true;
				updateToggle_AutoFire = true;
			} else {
				isToggle_AutoFireFirstCall = false;
			}
		}
		//Ammo
		bool isAmmo = false;
		bool updateToggle_Ammo = false;
		bool isToggle_AmmoFirstCall = true;
		void Toggle_Ammo() {
			if (!isToggle_AmmoFirstCall) {
				isAmmo = true;
				updateToggle_Ammo = true;
			} else {
				isToggle_AmmoFirstCall = false;
			}
		}
		//Ammo
		int SeekBar_Ammo = 1;
		bool updateSeekBar_Ammo = false;
		bool isSeekBar_AmmoFirstCall = true;
		void SetSeekBar_Ammo(int value) {
			if (!isSeekBar_AmmoFirstCall) {
				SeekBar_Ammo = value;
				updateSeekBar_Ammo = true;
		} else {
				isSeekBar_AmmoFirstCall = false;
			}
		}
		//Clip Size
		bool isClipSize = false;
		bool updateToggle_ClipSize = false;
		bool isToggle_ClipSizeFirstCall = true;
		void Toggle_ClipSize() {
			if (!isToggle_ClipSizeFirstCall) {
				isClipSize = true;
				updateToggle_ClipSize = true;
			} else {
				isToggle_ClipSizeFirstCall = false;
			}
		}
		//Clip Size
		int SeekBar_ClipSize = 1;
		bool updateSeekBar_ClipSize = false;
		bool isSeekBar_ClipSizeFirstCall = true;
		void SetSeekBar_ClipSize(int value) {
			if (!isSeekBar_ClipSizeFirstCall) {
				SeekBar_ClipSize = value;
				updateSeekBar_ClipSize = true;
		} else {
				isSeekBar_ClipSizeFirstCall = false;
			}
		}
		//Accuracy
		bool isAccuracy = false;
		bool updateToggle_Accuracy = false;
		bool isToggle_AccuracyFirstCall = true;
		void Toggle_Accuracy() {
			if (!isToggle_AccuracyFirstCall) {
				isAccuracy = true;
				updateToggle_Accuracy = true;
			} else {
				isToggle_AccuracyFirstCall = false;
			}
		}
		//No Shoot Delay
		bool isNoShootDelay = false;
		bool updateToggle_NoShootDelay = false;
		bool isToggle_NoShootDelayFirstCall = true;
		void Toggle_NoShootDelay() {
			if (!isToggle_NoShootDelayFirstCall) {
				isNoShootDelay = true;
				updateToggle_NoShootDelay = true;
			} else {
				isToggle_NoShootDelayFirstCall = false;
			}
		}
		//Shoot Through Walls
		bool isShootThroughWalls = false;
		bool updateToggle_ShootThroughWalls = false;
		bool isToggle_ShootThroughWallsFirstCall = true;
		void Toggle_ShootThroughWalls() {
			if (!isToggle_ShootThroughWallsFirstCall) {
				isShootThroughWalls = true;
				updateToggle_ShootThroughWalls = true;
			} else {
				isToggle_ShootThroughWallsFirstCall = false;
			}
		}
		//Shoot Lasers
		bool isShootLasers = false;
		bool updateToggle_ShootLasers = false;
		bool isToggle_ShootLasersFirstCall = true;
		void Toggle_ShootLasers() {
			if (!isToggle_ShootLasersFirstCall) {
				isShootLasers = true;
				updateToggle_ShootLasers = true;
			} else {
				isToggle_ShootLasersFirstCall = false;
			}
		}
		//Silent
		bool isSilent = false;
		bool updateToggle_Silent = false;
		bool isToggle_SilentFirstCall = true;
		void Toggle_Silent() {
			if (!isToggle_SilentFirstCall) {
				isSilent = true;
				updateToggle_Silent = true;
			} else {
				isToggle_SilentFirstCall = false;
			}
		}
		//No Recoil
		bool isNoRecoil = false;
		bool updateToggle_NoRecoil = false;
		bool isToggle_NoRecoilFirstCall = true;
		void Toggle_NoRecoil() {
			if (!isToggle_NoRecoilFirstCall) {
				isNoRecoil = true;
				updateToggle_NoRecoil = true;
			} else {
				isToggle_NoRecoilFirstCall = false;
			}
		}
		//Hide Weapon
		bool isHideWeapon = false;
		bool updateToggle_HideWeapon = false;
		bool isToggle_HideWeaponFirstCall = true;
		void Toggle_HideWeapon() {
			if (!isToggle_HideWeaponFirstCall) {
				isHideWeapon = true;
				updateToggle_HideWeapon = true;
			} else {
				isToggle_HideWeaponFirstCall = false;
			}
		}
		//Scope Zoom
		bool isScopeZoom = false;
		bool updateToggle_ScopeZoom = false;
		bool isToggle_ScopeZoomFirstCall = true;
		void Toggle_ScopeZoom() {
			if (!isToggle_ScopeZoomFirstCall) {
				isScopeZoom = true;
				updateToggle_ScopeZoom = true;
			} else {
				isToggle_ScopeZoomFirstCall = false;
			}
		}
		//Scope Zoom
		int SeekBar_ScopeZoom = 1;
		bool updateSeekBar_ScopeZoom = false;
		bool isSeekBar_ScopeZoomFirstCall = true;
		void SetSeekBar_ScopeZoom(int value) {
			if (!isSeekBar_ScopeZoomFirstCall) {
				SeekBar_ScopeZoom = value;
				updateSeekBar_ScopeZoom = true;
		} else {
				isSeekBar_ScopeZoomFirstCall = false;
			}
		}
	};
	WeaponsHacks Weapons;

	struct AimbotHacks {
		//Aimbot
		bool isAimbot = false;
		bool updateToggle_Aimbot = false;
		bool isToggle_AimbotFirstCall = true;
		void Toggle_Aimbot() {
			if (!isToggle_AimbotFirstCall) {
				isAimbot = true;
				updateToggle_Aimbot = true;
			} else {
				isToggle_AimbotFirstCall = false;
			}
		}
		//OP Aim Assist
		bool isOpAimAssist = false;
		bool updateToggle_OpAimAssist = false;
		bool isToggle_OpAimAssistFirstCall = true;
		void Toggle_OpAimAssist() {
			if (!isToggle_OpAimAssistFirstCall) {
				isOpAimAssist = true;
				updateToggle_OpAimAssist = true;
			} else {
				isToggle_OpAimAssistFirstCall = false;
			}
		}
		//Auto Fire
		bool isAutoFire = false;
		bool updateToggle_AutoFire = false;
		bool isToggle_AutoFireFirstCall = true;
		void Toggle_AutoFire() {
			if (!isToggle_AutoFireFirstCall) {
				isAutoFire = true;
				updateToggle_AutoFire = true;
			} else {
				isToggle_AutoFireFirstCall = false;
			}
		}
		//Silent Aim
		bool isSilentAim = false;
		bool updateToggle_SilentAim = false;
		bool isToggle_SilentAimFirstCall = true;
		void Toggle_SilentAim() {
			if (!isToggle_SilentAimFirstCall) {
				isSilentAim = true;
				updateToggle_SilentAim = true;
			} else {
				isToggle_SilentAimFirstCall = false;
			}
		}
		//Silent Aim Radius
		int SeekBar_SilentAimRadius = 1;
		bool updateSeekBar_SilentAimRadius = false;
		bool isSeekBar_SilentAimRadiusFirstCall = true;
		void SetSeekBar_SilentAimRadius(int value) {
			if (!isSeekBar_SilentAimRadiusFirstCall) {
				SeekBar_SilentAimRadius = value;
				updateSeekBar_SilentAimRadius = true;
		} else {
				isSeekBar_SilentAimRadiusFirstCall = false;
			}
		}
	};
	AimbotHacks Aimbot;

	struct KillPlayersHacks {
		//Telekill
		bool isTelekill = false;
		bool updateToggle_Telekill = false;
		bool isToggle_TelekillFirstCall = true;
		void Toggle_Telekill() {
			if (!isToggle_TelekillFirstCall) {
				isTelekill = true;
				updateToggle_Telekill = true;
			} else {
				isToggle_TelekillFirstCall = false;
			}
		}
		//Masskill
		bool isMasskill = false;
		bool updateToggle_Masskill = false;
		bool isToggle_MasskillFirstCall = true;
		void Toggle_Masskill() {
			if (!isToggle_MasskillFirstCall) {
				isMasskill = true;
				updateToggle_Masskill = true;
			} else {
				isToggle_MasskillFirstCall = false;
			}
		}
		//Kill All
		bool Button_isKillAll = false;
		bool updateButton_KillAll = false;
		bool isButton_KillAllFirstCall = true;
		void Button_KillAll() {
			if (!isButton_KillAllFirstCall) {
				Button_isKillAll = true;
				updateButton_KillAll = true;
			} else {
				isButton_KillAllFirstCall = false;
			}
		}
		//Spam Kill All
		bool isSpamKillAll = false;
		bool updateToggle_SpamKillAll = false;
		bool isToggle_SpamKillAllFirstCall = true;
		void Toggle_SpamKillAll() {
			if (!isToggle_SpamKillAllFirstCall) {
				isSpamKillAll = true;
				updateToggle_SpamKillAll = true;
			} else {
				isToggle_SpamKillAllFirstCall = false;
			}
		}
		//Player To Kill (Case Sensitive!)
		std::string InputText_PlayerToKillCaseSensitive = "Default";
		bool updateInputText_PlayerToKillCaseSensitive = false;
		bool isInputText_PlayerToKillCaseSensitiveFirstCall = true;
		void SetInputText_PlayerToKillCaseSensitive(std::string value) {
			if (!isInputText_PlayerToKillCaseSensitiveFirstCall) {
				InputText_PlayerToKillCaseSensitive = value;
				updateInputText_PlayerToKillCaseSensitive = true;
		} else {
				isInputText_PlayerToKillCaseSensitiveFirstCall = false;
			}
		}
		//Kill Player
		bool Button_isKillPlayer = false;
		bool updateButton_KillPlayer = false;
		bool isButton_KillPlayerFirstCall = true;
		void Button_KillPlayer() {
			if (!isButton_KillPlayerFirstCall) {
				Button_isKillPlayer = true;
				updateButton_KillPlayer = true;
			} else {
				isButton_KillPlayerFirstCall = false;
			}
		}
		//Spam Kill Player
		bool isSpamKillPlayer = false;
		bool updateToggle_SpamKillPlayer = false;
		bool isToggle_SpamKillPlayerFirstCall = true;
		void Toggle_SpamKillPlayer() {
			if (!isToggle_SpamKillPlayerFirstCall) {
				isSpamKillPlayer = true;
				updateToggle_SpamKillPlayer = true;
			} else {
				isToggle_SpamKillPlayerFirstCall = false;
			}
		}

		//Collapse Spam Kill Delay
		//Minutes
		int SpamKillDelay_SeekBar_Minutes = 1;
		bool updateSpamKillDelay_SeekBar_Minutes = false;
		bool isSpamKillDelay_SeekBar_MinutesFirstCall = true;
		void SpamKillDelay_SetSeekBar_Minutes(int value) {
			if (!isSpamKillDelay_SeekBar_MinutesFirstCall) {
				SpamKillDelay_SeekBar_Minutes = value;
				updateSpamKillDelay_SeekBar_Minutes = true;
		} else {
				isSpamKillDelay_SeekBar_MinutesFirstCall = false;
			}
		}
		//Seconds
		int SpamKillDelay_SeekBar_Seconds = 1;
		bool updateSpamKillDelay_SeekBar_Seconds = false;
		bool isSpamKillDelay_SeekBar_SecondsFirstCall = true;
		void SpamKillDelay_SetSeekBar_Seconds(int value) {
			if (!isSpamKillDelay_SeekBar_SecondsFirstCall) {
				SpamKillDelay_SeekBar_Seconds = value;
				updateSpamKillDelay_SeekBar_Seconds = true;
		} else {
				isSpamKillDelay_SeekBar_SecondsFirstCall = false;
			}
		}
		//Miliseconds
		int SpamKillDelay_SeekBar_Miliseconds = 1;
		bool updateSpamKillDelay_SeekBar_Miliseconds = false;
		bool isSpamKillDelay_SeekBar_MilisecondsFirstCall = true;
		void SpamKillDelay_SetSeekBar_Miliseconds(int value) {
			if (!isSpamKillDelay_SeekBar_MilisecondsFirstCall) {
				SpamKillDelay_SeekBar_Miliseconds = value;
				updateSpamKillDelay_SeekBar_Miliseconds = true;
		} else {
				isSpamKillDelay_SeekBar_MilisecondsFirstCall = false;
			}
		}
	};
	KillPlayersHacks KillPlayers;

	struct GrenadesHacks {
		//Infinite Grenades
		bool isInfiniteGrenades = false;
		bool updateToggle_InfiniteGrenades = false;
		bool isToggle_InfiniteGrenadesFirstCall = true;
		void Toggle_InfiniteGrenades() {
			if (!isToggle_InfiniteGrenadesFirstCall) {
				isInfiniteGrenades = true;
				updateToggle_InfiniteGrenades = true;
			} else {
				isToggle_InfiniteGrenadesFirstCall = false;
			}
		}
		//Grenade Spam
		bool isGrenadeSpam = false;
		bool updateToggle_GrenadeSpam = false;
		bool isToggle_GrenadeSpamFirstCall = true;
		void Toggle_GrenadeSpam() {
			if (!isToggle_GrenadeSpamFirstCall) {
				isGrenadeSpam = true;
				updateToggle_GrenadeSpam = true;
			} else {
				isToggle_GrenadeSpamFirstCall = false;
			}
		}
		//No Grenade Animation
		bool isNoGrenadeAnimation = false;
		bool updateToggle_NoGrenadeAnimation = false;
		bool isToggle_NoGrenadeAnimationFirstCall = true;
		void Toggle_NoGrenadeAnimation() {
			if (!isToggle_NoGrenadeAnimationFirstCall) {
				isNoGrenadeAnimation = true;
				updateToggle_NoGrenadeAnimation = true;
			} else {
				isToggle_NoGrenadeAnimationFirstCall = false;
			}
		}
	};
	GrenadesHacks Grenades;

	struct VisionHacks {
		//Collapse ESP
		//Player Lines
		bool Esp_isPlayerLines = false;
		bool updateEsp_Toggle_PlayerLines = false;
		bool isEsp_Toggle_PlayerLinesFirstCall = true;
		void Esp_Toggle_PlayerLines() {
			if (!isEsp_Toggle_PlayerLinesFirstCall) {
				Esp_isPlayerLines = true;
				updateEsp_Toggle_PlayerLines = true;
			} else {
				isEsp_Toggle_PlayerLinesFirstCall = false;
			}
		}
		//Player Boxes
		bool Esp_isPlayerBoxes = false;
		bool updateEsp_Toggle_PlayerBoxes = false;
		bool isEsp_Toggle_PlayerBoxesFirstCall = true;
		void Esp_Toggle_PlayerBoxes() {
			if (!isEsp_Toggle_PlayerBoxesFirstCall) {
				Esp_isPlayerBoxes = true;
				updateEsp_Toggle_PlayerBoxes = true;
			} else {
				isEsp_Toggle_PlayerBoxesFirstCall = false;
			}
		}
		//Player Health Bars
		bool Esp_isPlayerHealthBars = false;
		bool updateEsp_Toggle_PlayerHealthBars = false;
		bool isEsp_Toggle_PlayerHealthBarsFirstCall = true;
		void Esp_Toggle_PlayerHealthBars() {
			if (!isEsp_Toggle_PlayerHealthBarsFirstCall) {
				Esp_isPlayerHealthBars = true;
				updateEsp_Toggle_PlayerHealthBars = true;
			} else {
				isEsp_Toggle_PlayerHealthBarsFirstCall = false;
			}
		}
		//Player List
		bool Esp_isPlayerList = false;
		bool updateEsp_Toggle_PlayerList = false;
		bool isEsp_Toggle_PlayerListFirstCall = true;
		void Esp_Toggle_PlayerList() {
			if (!isEsp_Toggle_PlayerListFirstCall) {
				Esp_isPlayerList = true;
				updateEsp_Toggle_PlayerList = true;
			} else {
				isEsp_Toggle_PlayerListFirstCall = false;
			}
		}

		//Chams
		bool isChams = false;
		bool updateToggle_Chams = false;
		bool isToggle_ChamsFirstCall = true;
		void Toggle_Chams() {
			if (!isToggle_ChamsFirstCall) {
				isChams = true;
				updateToggle_Chams = true;
			} else {
				isToggle_ChamsFirstCall = false;
			}
		}
		//Xray
		bool isXray = false;
		bool updateToggle_Xray = false;
		bool isToggle_XrayFirstCall = true;
		void Toggle_Xray() {
			if (!isToggle_XrayFirstCall) {
				isXray = true;
				updateToggle_Xray = true;
			} else {
				isToggle_XrayFirstCall = false;
			}
		}
		//Custom FOV
		bool isCustomFov = false;
		bool updateToggle_CustomFov = false;
		bool isToggle_CustomFovFirstCall = true;
		void Toggle_CustomFov() {
			if (!isToggle_CustomFovFirstCall) {
				isCustomFov = true;
				updateToggle_CustomFov = true;
			} else {
				isToggle_CustomFovFirstCall = false;
			}
		}
		//FOV
		int SeekBar_Fov = 1;
		bool updateSeekBar_Fov = false;
		bool isSeekBar_FovFirstCall = true;
		void SetSeekBar_Fov(int value) {
			if (!isSeekBar_FovFirstCall) {
				SeekBar_Fov = value;
				updateSeekBar_Fov = true;
		} else {
				isSeekBar_FovFirstCall = false;
			}
		}
		//Disable Fog
		bool isDisableFog = false;
		bool updateToggle_DisableFog = false;
		bool isToggle_DisableFogFirstCall = true;
		void Toggle_DisableFog() {
			if (!isToggle_DisableFogFirstCall) {
				isDisableFog = true;
				updateToggle_DisableFog = true;
			} else {
				isToggle_DisableFogFirstCall = false;
			}
		}

		//Collapse Perspective
		//First Person
		bool Perspective_isFirstPerson = false;
		bool updatePerspective_CheckBox_FirstPerson = false;
		bool isPerspective_CheckBox_FirstPersonFirstCall = true;
		void Perspective_CheckBox_FirstPerson() {
			if (!isPerspective_CheckBox_FirstPersonFirstCall) {
				Perspective_isFirstPerson = true;
				updatePerspective_CheckBox_FirstPerson = true;
			} else {
				isPerspective_CheckBox_FirstPersonFirstCall = false;
			}
		}
		//Third Person
		bool Perspective_isThirdPerson = false;
		bool updatePerspective_CheckBox_ThirdPerson = false;
		bool isPerspective_CheckBox_ThirdPersonFirstCall = true;
		void Perspective_CheckBox_ThirdPerson() {
			if (!isPerspective_CheckBox_ThirdPersonFirstCall) {
				Perspective_isThirdPerson = true;
				updatePerspective_CheckBox_ThirdPerson = true;
			} else {
				isPerspective_CheckBox_ThirdPersonFirstCall = false;
			}
		}
	};
	VisionHacks Vision;

	struct EffectsHacks {
		//Anti-Freeze
		bool isAntiFreeze = false;
		bool updateToggle_AntiFreeze = false;
		bool isToggle_AntiFreezeFirstCall = true;
		void Toggle_AntiFreeze() {
			if (!isToggle_AntiFreezeFirstCall) {
				isAntiFreeze = true;
				updateToggle_AntiFreeze = true;
			} else {
				isToggle_AntiFreezeFirstCall = false;
			}
		}
		//Anti Camera Shake
		bool isAntiCameraShake = false;
		bool updateToggle_AntiCameraShake = false;
		bool isToggle_AntiCameraShakeFirstCall = true;
		void Toggle_AntiCameraShake() {
			if (!isToggle_AntiCameraShakeFirstCall) {
				isAntiCameraShake = true;
				updateToggle_AntiCameraShake = true;
			} else {
				isToggle_AntiCameraShakeFirstCall = false;
			}
		}
	};
	EffectsHacks Effects;

	struct MovementHacks {
		//Fly
		bool isFly = false;
		bool updateToggle_Fly = false;
		bool isToggle_FlyFirstCall = true;
		void Toggle_Fly() {
			if (!isToggle_FlyFirstCall) {
				isFly = true;
				updateToggle_Fly = true;
			} else {
				isToggle_FlyFirstCall = false;
			}
		}
		//Infinite Jump
		bool isInfiniteJump = false;
		bool updateToggle_InfiniteJump = false;
		bool isToggle_InfiniteJumpFirstCall = true;
		void Toggle_InfiniteJump() {
			if (!isToggle_InfiniteJumpFirstCall) {
				isInfiniteJump = true;
				updateToggle_InfiniteJump = true;
			} else {
				isToggle_InfiniteJumpFirstCall = false;
			}
		}
		//Jump Height
		bool isJumpHeight = false;
		bool updateToggle_JumpHeight = false;
		bool isToggle_JumpHeightFirstCall = true;
		void Toggle_JumpHeight() {
			if (!isToggle_JumpHeightFirstCall) {
				isJumpHeight = true;
				updateToggle_JumpHeight = true;
			} else {
				isToggle_JumpHeightFirstCall = false;
			}
		}
		//Jump Height
		int SeekBar_JumpHeight = 1;
		bool updateSeekBar_JumpHeight = false;
		bool isSeekBar_JumpHeightFirstCall = true;
		void SetSeekBar_JumpHeight(int value) {
			if (!isSeekBar_JumpHeightFirstCall) {
				SeekBar_JumpHeight = value;
				updateSeekBar_JumpHeight = true;
		} else {
				isSeekBar_JumpHeightFirstCall = false;
			}
		}
		//Inverted Jump
		bool isInvertedJump = false;
		bool updateToggle_InvertedJump = false;
		bool isToggle_InvertedJumpFirstCall = true;
		void Toggle_InvertedJump() {
			if (!isToggle_InvertedJumpFirstCall) {
				isInvertedJump = true;
				updateToggle_InvertedJump = true;
			} else {
				isToggle_InvertedJumpFirstCall = false;
			}
		}
		//Bunny Hop
		bool isBunnyHop = false;
		bool updateToggle_BunnyHop = false;
		bool isToggle_BunnyHopFirstCall = true;
		void Toggle_BunnyHop() {
			if (!isToggle_BunnyHopFirstCall) {
				isBunnyHop = true;
				updateToggle_BunnyHop = true;
			} else {
				isToggle_BunnyHopFirstCall = false;
			}
		}
		//Walk Speed
		bool isWalkSpeed = false;
		bool updateToggle_WalkSpeed = false;
		bool isToggle_WalkSpeedFirstCall = true;
		void Toggle_WalkSpeed() {
			if (!isToggle_WalkSpeedFirstCall) {
				isWalkSpeed = true;
				updateToggle_WalkSpeed = true;
			} else {
				isToggle_WalkSpeedFirstCall = false;
			}
		}
		//Walk Speed
		int SeekBar_WalkSpeed = 1;
		bool updateSeekBar_WalkSpeed = false;
		bool isSeekBar_WalkSpeedFirstCall = true;
		void SetSeekBar_WalkSpeed(int value) {
			if (!isSeekBar_WalkSpeedFirstCall) {
				SeekBar_WalkSpeed = value;
				updateSeekBar_WalkSpeed = true;
		} else {
				isSeekBar_WalkSpeedFirstCall = false;
			}
		}
		//Run Speed
		bool isRunSpeed = false;
		bool updateToggle_RunSpeed = false;
		bool isToggle_RunSpeedFirstCall = true;
		void Toggle_RunSpeed() {
			if (!isToggle_RunSpeedFirstCall) {
				isRunSpeed = true;
				updateToggle_RunSpeed = true;
			} else {
				isToggle_RunSpeedFirstCall = false;
			}
		}
		//Run Speed
		int SeekBar_RunSpeed = 1;
		bool updateSeekBar_RunSpeed = false;
		bool isSeekBar_RunSpeedFirstCall = true;
		void SetSeekBar_RunSpeed(int value) {
			if (!isSeekBar_RunSpeedFirstCall) {
				SeekBar_RunSpeed = value;
				updateSeekBar_RunSpeed = true;
		} else {
				isSeekBar_RunSpeedFirstCall = false;
			}
		}
		//Sprint Speed
		bool isSprintSpeed = false;
		bool updateToggle_SprintSpeed = false;
		bool isToggle_SprintSpeedFirstCall = true;
		void Toggle_SprintSpeed() {
			if (!isToggle_SprintSpeedFirstCall) {
				isSprintSpeed = true;
				updateToggle_SprintSpeed = true;
			} else {
				isToggle_SprintSpeedFirstCall = false;
			}
		}
		//Sprint Speed
		int SeekBar_SprintSpeed = 1;
		bool updateSeekBar_SprintSpeed = false;
		bool isSeekBar_SprintSpeedFirstCall = true;
		void SetSeekBar_SprintSpeed(int value) {
			if (!isSeekBar_SprintSpeedFirstCall) {
				SeekBar_SprintSpeed = value;
				updateSeekBar_SprintSpeed = true;
		} else {
				isSeekBar_SprintSpeedFirstCall = false;
			}
		}
		//Auto Sprint
		bool isAutoSprint = false;
		bool updateToggle_AutoSprint = false;
		bool isToggle_AutoSprintFirstCall = true;
		void Toggle_AutoSprint() {
			if (!isToggle_AutoSprintFirstCall) {
				isAutoSprint = true;
				updateToggle_AutoSprint = true;
			} else {
				isToggle_AutoSprintFirstCall = false;
			}
		}
		//No Clip
		bool isNoClip = false;
		bool updateToggle_NoClip = false;
		bool isToggle_NoClipFirstCall = true;
		void Toggle_NoClip() {
			if (!isToggle_NoClipFirstCall) {
				isNoClip = true;
				updateToggle_NoClip = true;
			} else {
				isToggle_NoClipFirstCall = false;
			}
		}
		//Underwater
		bool isUnderwater = false;
		bool updateToggle_Underwater = false;
		bool isToggle_UnderwaterFirstCall = true;
		void Toggle_Underwater() {
			if (!isToggle_UnderwaterFirstCall) {
				isUnderwater = true;
				updateToggle_Underwater = true;
			} else {
				isToggle_UnderwaterFirstCall = false;
			}
		}

		//Collapse Gravity
		//Gravity Strength
		bool Gravity_isGravityStrength = false;
		bool updateGravity_Toggle_GravityStrength = false;
		bool isGravity_Toggle_GravityStrengthFirstCall = true;
		void Gravity_Toggle_GravityStrength() {
			if (!isGravity_Toggle_GravityStrengthFirstCall) {
				Gravity_isGravityStrength = true;
				updateGravity_Toggle_GravityStrength = true;
			} else {
				isGravity_Toggle_GravityStrengthFirstCall = false;
			}
		}
		//Gravity
		int Gravity_SeekBar_Gravity = 1;
		bool updateGravity_SeekBar_Gravity = false;
		bool isGravity_SeekBar_GravityFirstCall = true;
		void Gravity_SetSeekBar_Gravity(int value) {
			if (!isGravity_SeekBar_GravityFirstCall) {
				Gravity_SeekBar_Gravity = value;
				updateGravity_SeekBar_Gravity = true;
		} else {
				isGravity_SeekBar_GravityFirstCall = false;
			}
		}
		//Inverted Gravity
		bool Gravity_isInvertedGravity = false;
		bool updateGravity_Toggle_InvertedGravity = false;
		bool isGravity_Toggle_InvertedGravityFirstCall = true;
		void Gravity_Toggle_InvertedGravity() {
			if (!isGravity_Toggle_InvertedGravityFirstCall) {
				Gravity_isInvertedGravity = true;
				updateGravity_Toggle_InvertedGravity = true;
			} else {
				isGravity_Toggle_InvertedGravityFirstCall = false;
			}
		}

		//Collapse Teleport
		//X
		int Teleport_InputValue_X = 1;
		bool updateTeleport_InputValue_X = false;
		bool isTeleport_InputValue_XFirstCall = true;
		void Teleport_SetInputValue_X(int value) {
			if (!isTeleport_InputValue_XFirstCall) {
				Teleport_InputValue_X = value;
				updateTeleport_InputValue_X = true;
		} else {
				isTeleport_InputValue_XFirstCall = false;
			}
		}
		//Y
		int Teleport_InputValue_Y = 1;
		bool updateTeleport_InputValue_Y = false;
		bool isTeleport_InputValue_YFirstCall = true;
		void Teleport_SetInputValue_Y(int value) {
			if (!isTeleport_InputValue_YFirstCall) {
				Teleport_InputValue_Y = value;
				updateTeleport_InputValue_Y = true;
		} else {
				isTeleport_InputValue_YFirstCall = false;
			}
		}
		//Z
		int Teleport_InputValue_Z = 1;
		bool updateTeleport_InputValue_Z = false;
		bool isTeleport_InputValue_ZFirstCall = true;
		void Teleport_SetInputValue_Z(int value) {
			if (!isTeleport_InputValue_ZFirstCall) {
				Teleport_InputValue_Z = value;
				updateTeleport_InputValue_Z = true;
		} else {
				isTeleport_InputValue_ZFirstCall = false;
			}
		}
		//Teleport
		bool Teleport_Button_isTeleport = false;
		bool updateTeleport_Button_Teleport = false;
		bool isTeleport_Button_TeleportFirstCall = true;
		void Teleport_Button_Teleport() {
			if (!isTeleport_Button_TeleportFirstCall) {
				Teleport_Button_isTeleport = true;
				updateTeleport_Button_Teleport = true;
			} else {
				isTeleport_Button_TeleportFirstCall = false;
			}
		}
	};
	MovementHacks Movement;

	struct RespawningHacks {
		//Respawn
		bool Button_isRespawn = false;
		bool updateButton_Respawn = false;
		bool isButton_RespawnFirstCall = true;
		void Button_Respawn() {
			if (!isButton_RespawnFirstCall) {
				Button_isRespawn = true;
				updateButton_Respawn = true;
			} else {
				isButton_RespawnFirstCall = false;
			}
		}
		//Immediate Respawn
		bool isImmediateRespawn = false;
		bool updateToggle_ImmediateRespawn = false;
		bool isToggle_ImmediateRespawnFirstCall = true;
		void Toggle_ImmediateRespawn() {
			if (!isToggle_ImmediateRespawnFirstCall) {
				isImmediateRespawn = true;
				updateToggle_ImmediateRespawn = true;
			} else {
				isToggle_ImmediateRespawnFirstCall = false;
			}
		}
		//Respawn In Place
		bool isRespawnInPlace = false;
		bool updateToggle_RespawnInPlace = false;
		bool isToggle_RespawnInPlaceFirstCall = true;
		void Toggle_RespawnInPlace() {
			if (!isToggle_RespawnInPlaceFirstCall) {
				isRespawnInPlace = true;
				updateToggle_RespawnInPlace = true;
			} else {
				isToggle_RespawnInPlaceFirstCall = false;
			}
		}
		//Don't Respawn
		bool isDisableRespawn = false;
		bool updateToggle_DisableRespawn = false;
		bool isToggle_DisableRespawnFirstCall = true;
		void Toggle_DisableRespawn() {
			if (!isToggle_DisableRespawnFirstCall) {
				isDisableRespawn = true;
				updateToggle_DisableRespawn = true;
			} else {
				isToggle_DisableRespawnFirstCall = false;
			}
		}

		//Collapse Custom Respawn Positon
		//X
		int CustomRespawnPositon_InputValue_X = 1;
		bool updateCustomRespawnPositon_InputValue_X = false;
		bool isCustomRespawnPositon_InputValue_XFirstCall = true;
		void CustomRespawnPositon_SetInputValue_X(int value) {
			if (!isCustomRespawnPositon_InputValue_XFirstCall) {
				CustomRespawnPositon_InputValue_X = value;
				updateCustomRespawnPositon_InputValue_X = true;
		} else {
				isCustomRespawnPositon_InputValue_XFirstCall = false;
			}
		}
		//Y
		int CustomRespawnPositon_InputValue_Y = 1;
		bool updateCustomRespawnPositon_InputValue_Y = false;
		bool isCustomRespawnPositon_InputValue_YFirstCall = true;
		void CustomRespawnPositon_SetInputValue_Y(int value) {
			if (!isCustomRespawnPositon_InputValue_YFirstCall) {
				CustomRespawnPositon_InputValue_Y = value;
				updateCustomRespawnPositon_InputValue_Y = true;
		} else {
				isCustomRespawnPositon_InputValue_YFirstCall = false;
			}
		}
		//Z
		int CustomRespawnPositon_InputValue_Z = 1;
		bool updateCustomRespawnPositon_InputValue_Z = false;
		bool isCustomRespawnPositon_InputValue_ZFirstCall = true;
		void CustomRespawnPositon_SetInputValue_Z(int value) {
			if (!isCustomRespawnPositon_InputValue_ZFirstCall) {
				CustomRespawnPositon_InputValue_Z = value;
				updateCustomRespawnPositon_InputValue_Z = true;
		} else {
				isCustomRespawnPositon_InputValue_ZFirstCall = false;
			}
		}
		//Custom Respawn Position
		bool CustomRespawnPositon_isCustomRespawnPosition = false;
		bool updateCustomRespawnPositon_CheckBox_CustomRespawnPosition = false;
		bool isCustomRespawnPositon_CheckBox_CustomRespawnPositionFirstCall = true;
		void CustomRespawnPositon_CheckBox_CustomRespawnPosition() {
			if (!isCustomRespawnPositon_CheckBox_CustomRespawnPositionFirstCall) {
				CustomRespawnPositon_isCustomRespawnPosition = true;
				updateCustomRespawnPositon_CheckBox_CustomRespawnPosition = true;
			} else {
				isCustomRespawnPositon_CheckBox_CustomRespawnPositionFirstCall = false;
			}
		}
	};
	RespawningHacks Respawning;

	struct VehiclesHacks {
		//Vehicle Infinite Health
		bool isVehicleInfiniteHealth = false;
		bool updateToggle_VehicleInfiniteHealth = false;
		bool isToggle_VehicleInfiniteHealthFirstCall = true;
		void Toggle_VehicleInfiniteHealth() {
			if (!isToggle_VehicleInfiniteHealthFirstCall) {
				isVehicleInfiniteHealth = true;
				updateToggle_VehicleInfiniteHealth = true;
			} else {
				isToggle_VehicleInfiniteHealthFirstCall = false;
			}
		}
		//Vehicle Godmode
		bool isVehicleGodmode = false;
		bool updateToggle_VehicleGodmode = false;
		bool isToggle_VehicleGodmodeFirstCall = true;
		void Toggle_VehicleGodmode() {
			if (!isToggle_VehicleGodmodeFirstCall) {
				isVehicleGodmode = true;
				updateToggle_VehicleGodmode = true;
			} else {
				isToggle_VehicleGodmodeFirstCall = false;
			}
		}

		//Collapse Teleport Vehicle
		//X
		int TeleportVehicle_InputValue_X = 1;
		bool updateTeleportVehicle_InputValue_X = false;
		bool isTeleportVehicle_InputValue_XFirstCall = true;
		void TeleportVehicle_SetInputValue_X(int value) {
			if (!isTeleportVehicle_InputValue_XFirstCall) {
				TeleportVehicle_InputValue_X = value;
				updateTeleportVehicle_InputValue_X = true;
		} else {
				isTeleportVehicle_InputValue_XFirstCall = false;
			}
		}
		//Y
		int TeleportVehicle_InputValue_Y = 1;
		bool updateTeleportVehicle_InputValue_Y = false;
		bool isTeleportVehicle_InputValue_YFirstCall = true;
		void TeleportVehicle_SetInputValue_Y(int value) {
			if (!isTeleportVehicle_InputValue_YFirstCall) {
				TeleportVehicle_InputValue_Y = value;
				updateTeleportVehicle_InputValue_Y = true;
		} else {
				isTeleportVehicle_InputValue_YFirstCall = false;
			}
		}
		//Z
		int TeleportVehicle_InputValue_Z = 1;
		bool updateTeleportVehicle_InputValue_Z = false;
		bool isTeleportVehicle_InputValue_ZFirstCall = true;
		void TeleportVehicle_SetInputValue_Z(int value) {
			if (!isTeleportVehicle_InputValue_ZFirstCall) {
				TeleportVehicle_InputValue_Z = value;
				updateTeleportVehicle_InputValue_Z = true;
		} else {
				isTeleportVehicle_InputValue_ZFirstCall = false;
			}
		}
		//Teleport
		bool TeleportVehicle_Button_isTeleport = false;
		bool updateTeleportVehicle_Button_Teleport = false;
		bool isTeleportVehicle_Button_TeleportFirstCall = true;
		void TeleportVehicle_Button_Teleport() {
			if (!isTeleportVehicle_Button_TeleportFirstCall) {
				TeleportVehicle_Button_isTeleport = true;
				updateTeleportVehicle_Button_Teleport = true;
			} else {
				isTeleportVehicle_Button_TeleportFirstCall = false;
			}
		}

		//Collapse Spawn Vehicle
		//X
		int SpawnVehicle_InputValue_X = 1;
		bool updateSpawnVehicle_InputValue_X = false;
		bool isSpawnVehicle_InputValue_XFirstCall = true;
		void SpawnVehicle_SetInputValue_X(int value) {
			if (!isSpawnVehicle_InputValue_XFirstCall) {
				SpawnVehicle_InputValue_X = value;
				updateSpawnVehicle_InputValue_X = true;
		} else {
				isSpawnVehicle_InputValue_XFirstCall = false;
			}
		}
		//Y
		int SpawnVehicle_InputValue_Y = 1;
		bool updateSpawnVehicle_InputValue_Y = false;
		bool isSpawnVehicle_InputValue_YFirstCall = true;
		void SpawnVehicle_SetInputValue_Y(int value) {
			if (!isSpawnVehicle_InputValue_YFirstCall) {
				SpawnVehicle_InputValue_Y = value;
				updateSpawnVehicle_InputValue_Y = true;
		} else {
				isSpawnVehicle_InputValue_YFirstCall = false;
			}
		}
		//Z
		int SpawnVehicle_InputValue_Z = 1;
		bool updateSpawnVehicle_InputValue_Z = false;
		bool isSpawnVehicle_InputValue_ZFirstCall = true;
		void SpawnVehicle_SetInputValue_Z(int value) {
			if (!isSpawnVehicle_InputValue_ZFirstCall) {
				SpawnVehicle_InputValue_Z = value;
				updateSpawnVehicle_InputValue_Z = true;
		} else {
				isSpawnVehicle_InputValue_ZFirstCall = false;
			}
		}
		//Spawn Vehicle
		bool SpawnVehicle_Button_isSpawnVehicle = false;
		bool updateSpawnVehicle_Button_SpawnVehicle = false;
		bool isSpawnVehicle_Button_SpawnVehicleFirstCall = true;
		void SpawnVehicle_Button_SpawnVehicle() {
			if (!isSpawnVehicle_Button_SpawnVehicleFirstCall) {
				SpawnVehicle_Button_isSpawnVehicle = true;
				updateSpawnVehicle_Button_SpawnVehicle = true;
			} else {
				isSpawnVehicle_Button_SpawnVehicleFirstCall = false;
			}
		}
	};
	VehiclesHacks Vehicles;

	struct ScoreHacks {
		//Collapse Score
		//Score
		int Score_InputValue_Score = 1;
		bool updateScore_InputValue_Score = false;
		bool isScore_InputValue_ScoreFirstCall = true;
		void Score_SetInputValue_Score(int value) {
			if (!isScore_InputValue_ScoreFirstCall) {
				Score_InputValue_Score = value;
				updateScore_InputValue_Score = true;
		} else {
				isScore_InputValue_ScoreFirstCall = false;
			}
		}
		//Set Score
		bool Score_Button_isSetScore = false;
		bool updateScore_Button_SetScore = false;
		bool isScore_Button_SetScoreFirstCall = true;
		void Score_Button_SetScore() {
			if (!isScore_Button_SetScoreFirstCall) {
				Score_Button_isSetScore = true;
				updateScore_Button_SetScore = true;
			} else {
				isScore_Button_SetScoreFirstCall = false;
			}
		}

		//Collapse Kills
		//Kills
		int Kills_InputValue_Kills = 1;
		bool updateKills_InputValue_Kills = false;
		bool isKills_InputValue_KillsFirstCall = true;
		void Kills_SetInputValue_Kills(int value) {
			if (!isKills_InputValue_KillsFirstCall) {
				Kills_InputValue_Kills = value;
				updateKills_InputValue_Kills = true;
		} else {
				isKills_InputValue_KillsFirstCall = false;
			}
		}
		//Set Kills
		bool Kills_Button_isSetKills = false;
		bool updateKills_Button_SetKills = false;
		bool isKills_Button_SetKillsFirstCall = true;
		void Kills_Button_SetKills() {
			if (!isKills_Button_SetKillsFirstCall) {
				Kills_Button_isSetKills = true;
				updateKills_Button_SetKills = true;
			} else {
				isKills_Button_SetKillsFirstCall = false;
			}
		}

		//Collapse Killstreak
		//Killstreak
		int Killstreak_InputValue_Killstreak = 1;
		bool updateKillstreak_InputValue_Killstreak = false;
		bool isKillstreak_InputValue_KillstreakFirstCall = true;
		void Killstreak_SetInputValue_Killstreak(int value) {
			if (!isKillstreak_InputValue_KillstreakFirstCall) {
				Killstreak_InputValue_Killstreak = value;
				updateKillstreak_InputValue_Killstreak = true;
		} else {
				isKillstreak_InputValue_KillstreakFirstCall = false;
			}
		}
		//Set Killstreak
		bool Killstreak_Button_isSetKillstreak = false;
		bool updateKillstreak_Button_SetKillstreak = false;
		bool isKillstreak_Button_SetKillstreakFirstCall = true;
		void Killstreak_Button_SetKillstreak() {
			if (!isKillstreak_Button_SetKillstreakFirstCall) {
				Killstreak_Button_isSetKillstreak = true;
				updateKillstreak_Button_SetKillstreak = true;
			} else {
				isKillstreak_Button_SetKillstreakFirstCall = false;
			}
		}
	};
	ScoreHacks Score;

	struct BotsHacks {
		//Disable Bots
		bool isDisableBots = false;
		bool updateToggle_DisableBots = false;
		bool isToggle_DisableBotsFirstCall = true;
		void Toggle_DisableBots() {
			if (!isToggle_DisableBotsFirstCall) {
				isDisableBots = true;
				updateToggle_DisableBots = true;
			} else {
				isToggle_DisableBotsFirstCall = false;
			}
		}
		//Remove Bots
		bool Button_isRemoveBots = false;
		bool updateButton_RemoveBots = false;
		bool isButton_RemoveBotsFirstCall = true;
		void Button_RemoveBots() {
			if (!isButton_RemoveBotsFirstCall) {
				Button_isRemoveBots = true;
				updateButton_RemoveBots = true;
			} else {
				isButton_RemoveBotsFirstCall = false;
			}
		}
		//Kill Bots
		bool Button_isKillBots = false;
		bool updateButton_KillBots = false;
		bool isButton_KillBotsFirstCall = true;
		void Button_KillBots() {
			if (!isButton_KillBotsFirstCall) {
				Button_isKillBots = true;
				updateButton_KillBots = true;
			} else {
				isButton_KillBotsFirstCall = false;
			}
		}

		//Collapse Add Bots
		//Blue Team
		bool AddBots_isBlueTeam = false;
		bool updateAddBots_CheckBox_BlueTeam = false;
		bool isAddBots_CheckBox_BlueTeamFirstCall = true;
		void AddBots_CheckBox_BlueTeam() {
			if (!isAddBots_CheckBox_BlueTeamFirstCall) {
				AddBots_isBlueTeam = true;
				updateAddBots_CheckBox_BlueTeam = true;
			} else {
				isAddBots_CheckBox_BlueTeamFirstCall = false;
			}
		}
		//Red Team
		bool AddBots_isRedTeam = false;
		bool updateAddBots_CheckBox_RedTeam = false;
		bool isAddBots_CheckBox_RedTeamFirstCall = true;
		void AddBots_CheckBox_RedTeam() {
			if (!isAddBots_CheckBox_RedTeamFirstCall) {
				AddBots_isRedTeam = true;
				updateAddBots_CheckBox_RedTeam = true;
			} else {
				isAddBots_CheckBox_RedTeamFirstCall = false;
			}
		}
		//Name
		std::string AddBots_InputText_Name = "Default";
		bool updateAddBots_InputText_Name = false;
		bool isAddBots_InputText_NameFirstCall = true;
		void AddBots_SetInputText_Name(std::string value) {
			if (!isAddBots_InputText_NameFirstCall) {
				AddBots_InputText_Name = value;
				updateAddBots_InputText_Name = true;
		} else {
				isAddBots_InputText_NameFirstCall = false;
			}
		}
		//Add Bot
		bool AddBots_Button_isAddBot = false;
		bool updateAddBots_Button_AddBot = false;
		bool isAddBots_Button_AddBotFirstCall = true;
		void AddBots_Button_AddBot() {
			if (!isAddBots_Button_AddBotFirstCall) {
				AddBots_Button_isAddBot = true;
				updateAddBots_Button_AddBot = true;
			} else {
				isAddBots_Button_AddBotFirstCall = false;
			}
		}
	};
	BotsHacks Bots;

	struct MatchHacks {
		//Chat Spam
		bool isChatSpam = false;
		bool updateToggle_ChatSpam = false;
		bool isToggle_ChatSpamFirstCall = true;
		void Toggle_ChatSpam() {
			if (!isToggle_ChatSpamFirstCall) {
				isChatSpam = true;
				updateToggle_ChatSpam = true;
			} else {
				isToggle_ChatSpamFirstCall = false;
			}
		}

		//Collapse Match Time
		//Hours
		int MatchTime_InputValue_Hours = 1;
		bool updateMatchTime_InputValue_Hours = false;
		bool isMatchTime_InputValue_HoursFirstCall = true;
		void MatchTime_SetInputValue_Hours(int value) {
			if (!isMatchTime_InputValue_HoursFirstCall) {
				MatchTime_InputValue_Hours = value;
				updateMatchTime_InputValue_Hours = true;
		} else {
				isMatchTime_InputValue_HoursFirstCall = false;
			}
		}
		//Minutes
		int MatchTime_InputValue_Minutes = 1;
		bool updateMatchTime_InputValue_Minutes = false;
		bool isMatchTime_InputValue_MinutesFirstCall = true;
		void MatchTime_SetInputValue_Minutes(int value) {
			if (!isMatchTime_InputValue_MinutesFirstCall) {
				MatchTime_InputValue_Minutes = value;
				updateMatchTime_InputValue_Minutes = true;
		} else {
				isMatchTime_InputValue_MinutesFirstCall = false;
			}
		}
		//Seconds
		int MatchTime_InputValue_Seconds = 1;
		bool updateMatchTime_InputValue_Seconds = false;
		bool isMatchTime_InputValue_SecondsFirstCall = true;
		void MatchTime_SetInputValue_Seconds(int value) {
			if (!isMatchTime_InputValue_SecondsFirstCall) {
				MatchTime_InputValue_Seconds = value;
				updateMatchTime_InputValue_Seconds = true;
		} else {
				isMatchTime_InputValue_SecondsFirstCall = false;
			}
		}
		//Set Time
		bool MatchTime_Button_isSetTime = false;
		bool updateMatchTime_Button_SetTime = false;
		bool isMatchTime_Button_SetTimeFirstCall = true;
		void MatchTime_Button_SetTime() {
			if (!isMatchTime_Button_SetTimeFirstCall) {
				MatchTime_Button_isSetTime = true;
				updateMatchTime_Button_SetTime = true;
			} else {
				isMatchTime_Button_SetTimeFirstCall = false;
			}
		}
		//Freeze Match Tine
		bool MatchTime_isFreezeMatchTine = false;
		bool updateMatchTime_CheckBox_FreezeMatchTine = false;
		bool isMatchTime_CheckBox_FreezeMatchTineFirstCall = true;
		void MatchTime_CheckBox_FreezeMatchTine() {
			if (!isMatchTime_CheckBox_FreezeMatchTineFirstCall) {
				MatchTime_isFreezeMatchTine = true;
				updateMatchTime_CheckBox_FreezeMatchTine = true;
			} else {
				isMatchTime_CheckBox_FreezeMatchTineFirstCall = false;
			}
		}
	};
	MatchHacks Match;

	struct MiscellaneousHacks {
		//Antiban
		bool isAntiban = true;
		bool updateCheckBox_Antiban = false;
		bool isCheckBox_AntibanFirstCall = true;
		void CheckBox_Antiban() {
			if (!isCheckBox_AntibanFirstCall) {
				isAntiban = true;
				updateCheckBox_Antiban = true;
			} else {
				isCheckBox_AntibanFirstCall = false;
			}
		}
		//Bypass
		bool isBypass = false;
		bool updateCheckBox_Bypass = false;
		bool isCheckBox_BypassFirstCall = true;
		void CheckBox_Bypass() {
			if (!isCheckBox_BypassFirstCall) {
				isBypass = true;
				updateCheckBox_Bypass = true;
			} else {
				isCheckBox_BypassFirstCall = false;
			}
		}
		//No Ads
		bool isNoAds = true;
		bool updateCheckBox_NoAds = false;
		bool isCheckBox_NoAdsFirstCall = true;
		void CheckBox_NoAds() {
			if (!isCheckBox_NoAdsFirstCall) {
				isNoAds = true;
				updateCheckBox_NoAds = true;
			} else {
				isCheckBox_NoAdsFirstCall = false;
			}
		}
		//60 FPS
		bool is60Fps = false;
		bool updateCheckBox_60Fps = false;
		bool isCheckBox_60FpsFirstCall = true;
		void CheckBox_60Fps() {
			if (!isCheckBox_60FpsFirstCall) {
				is60Fps = true;
				updateCheckBox_60Fps = true;
			} else {
				isCheckBox_60FpsFirstCall = false;
			}
		}
	};
	MiscellaneousHacks Miscellaneous;
}