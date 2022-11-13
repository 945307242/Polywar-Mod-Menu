#if defined(__aarch64__)
namespace Offsets {
	struct FieldOffsets {
		//PlayerScript
		const uint64_t InfiniteGrenades = 0x140; //PlayerScript.frags

		//PlayerConfig
		const uint64_t AutoAimForce = 0x20; //PlayerController.autoaimForce
		const uint64_t AutoAimAngle = 0x10; //PlayerController.autoaimAngle
		const uint64_t ColliderRadius = 0x90; //PlayerController.colliderRadius
		const uint64_t SpreadSize = 0x5C; //PlayerController.spreadSize
		const uint64_t GrenadeThrowDelay = 0x1D4; //PlayerController.throwDelay

		//WeaponScript
		const uint64_t WeaponDamage = 0x194; //WeaponScript.Damage
		const uint64_t ClipSize = 0x18C; //WeaponScript.clipSize
		const uint64_t Bullets = 0x16C; //WeaponScript.bullets
		const uint64_t Clips = 0x178; //WeaponScript.clips
		const uint64_t Accuracy = 0x184; //WeaponScript.WeaponAccuracy
		const uint64_t ShootDelay = 0x180; //WeaponScript.shootDelay
		const uint64_t ShootLasers = 0x29D; //WeaponScript.isLaser
		const uint64_t Silent = 0x29A; //WeaponScript.isSilencer
		const uint64_t Recoil = 0x2F4; //WeaponScript.recoil

		//PlayerController
		const uint64_t JumpForce = 0x24; //PlayerController.jumpForce
		const uint64_t isGrounded = 0x50; //PlayerController.isGrounded
	};
	struct MethodOffsets {
		//WeaponScript
		const uint64_t WeaponScript_Update = 0x160D9D4; //WeaponScript.Update
		const uint64_t WeaponScript_CanShoot = 0x160B9C4; //WeaponScript.canShoot
		const uint64_t WeaponScript_HideWeapon = 0x160E280; //WeaponScript.HideWeapon
		const uint64_t WeaponScript_UseGrenade = 0x160F1D4; //WeaponScript.UseGrenade

		//PlayerScript
		const uint64_t PlayerScript_Update = 0x1523DE0; //PlayerScript.Update
		const uint64_t PlayerScript_get_throwingGrenade = 0x1510D98; //PlayerScript.get_throwingGrenade
		const uint64_t PlayerScript_Die = 0x152C174; //PlayerScript.Die
		const uint64_t PlayerScript_ChatMessage = 0x1527280; //PlayerScript.ChatMessage
		const uint64_t PlayerScript_ChatPlayerMessage = 0x1526FF4; //PlayerScript.ChatPlayerMessage
		const uint64_t PlayerScript_Respawn = 0x151A0A4; //PlayerScript.Respawn
		const uint64_t PlayerScript_Respawn_Internal = 0x15102E0; //PlayerScript._Respawn
		const uint64_t PlayerScript_Teleport = 0x1519764; //PlayerScript.Teleport

		//PlayerController
		const uint64_t PlayerController_Update = 0x150F7D0; //PlayerController.Update

		//UnityEngine.CharacterController
		const uint64_t UnityEngine_PlayerController_get_detectColisions = 0x1418714; //UnityEngine.CharacterController.get_detectCollisions

		//XAds
		const uint64_t XAds_Play = 0x17E5060; //XADS.Play

		//PriceValue
		const uint64_t PriceValue_get_price = 0x16E7DC8; //PriceValue.get_price
		
		//GameParamsScript
		const uint64_t GameParamsScript_get_isVIP = 0x1650600; //GameParamsScript.get_isVIP
		const uint64_t GameParamsScript_get_isBattlepassBought = 0x16504F4; //GameParamsScript.get_isBattlepassBought
		const uint64_t GameParamsScript_BanPlayer = 0x164E28C; //GameParamsScript.BanPlayer

		//SocialNetBase
		const uint64_t SocialNetBase_BuyVIP = 0x162E044; //SocialNetBase.BuyVIP

	};
	FieldOffsets Fields;
	MethodOffsets Methods;
}
#else
namespace Offsets {
	struct FieldOffsets {
		//PlayerScript
		const uint64_t InfiniteGrenades = 0x1C4; //PlayerScript.frags

		//PlayerConfig
		const uint64_t AutoAimForce = 0x38; //PlayerController.autoaimForce
		const uint64_t AutoAimAngle = 0x20; //PlayerController.autoaimAngle
		const uint64_t ColliderRadius = 0xB8; //PlayerController.colliderRadius
		const uint64_t SpreadSize = 0x7C; //PlayerController.spreadSize
		const uint64_t GrenadeThrowDelay = 0x248; //PlayerController.throwDelay

		//WeaponScript
		const uint64_t WeaponDamage = 0x298; //WeaponScript.Damage
		const uint64_t ClipSize = 0x290; //WeaponScript.clipSize
		const uint64_t Bullets = 0x270; //WeaponScript.bullets
		const uint64_t Clips = 0x27C; //WeaponScript.clips
		const uint64_t Accuracy = 0x184; //WeaponScript.WeaponAccuracy
		const uint64_t ShootDelay = 0xD8; //WeaponScript.shootDelay
		const uint64_t ShootLasers = 0x199; //WeaponScript.isLaser
		const uint64_t Silent = 0x196; //WeaponScript.isSilencer
		const uint64_t Recoil = 0x1CC; //WeaponScript.recoil

		//PlayerController
		const uint64_t JumpForce = 0x18; //PlayerController.jumpForce
		const uint64_t isGrounded = 0x3C; //PlayerController.isGrounded
	};
	struct MethodOffsets {
		//WeaponScript
		const uint64_t WeaponScript_Update = 0x14B13A0; //WeaponScript.Update
		const uint64_t WeaponScript_CanShoot = 0x14AE744; //WeaponScript.canShoot
		const uint64_t WeaponScript_HideWeapon = 0x14B1F90; //WeaponScript.HideWeapon
		const uint64_t WeaponScript_UseGrenade = 0x14B343C; //WeaponScript.UseGrenade

		//PlayerScript
		const uint64_t PlayerScript_Update = 0x138C7D8; //PlayerScript.Update
		const uint64_t PlayerScript_get_throwingGrenade = 0x1372754; //PlayerScript.get_throwingGrenade
		const uint64_t PlayerScript_Die = 0x13975D4; //PlayerScript.Die
		const uint64_t PlayerScript_ChatMessage = 0x1390DE0; //PlayerScript.ChatMessage
		const uint64_t PlayerScript_ChatPlayerMessage = 0x1390AE4; //PlayerScript.ChatPlayerMessage
		const uint64_t PlayerScript_Respawn = 0x137EFDC; //PlayerScript.Respawn
		const uint64_t PlayerScript_Respawn_Internal = 0x137184C; //PlayerScript._Respawn
		const uint64_t PlayerScript_Teleport = 0x137E430; //PlayerScript.Teleport

		//PlayerController
		const uint64_t PlayerController_Update = 0x1370A94; //PlayerController.Update

		//UnityEngine.CharacterController
		const uint64_t UnityEngine_PlayerController_get_detectColisions = 0x1247500; //UnityEngine.CharacterController.get_detectCollisions

		//XAds
		const uint64_t XAds_Play = 0x1709E08; //XADS.Play

		//PriceValue
		const uint64_t PriceValue_get_price= 0x15C8AF8; //PriceValue.get_price
		
		//GameParamsScript
		const uint64_t GameParamsScript_get_isVIP = 0x15095C0; //GameParamsScript.get_isVIP
		const uint64_t GameParamsScript_get_isBattlepassBought = 0x1509464; //GameParamsScript.get_isBattlepassBought
		const uint64_t GameParamsScript_BanPlayer = 0x1506878; //GameParamsScript.BanPlayer
				
		//SocialNetBase
		const uint64_t SocialNetBase_BuyVIP = 0x14DC400; //SocialNetBase.BuyVIP
	};
	FieldOffsets Fields;
	MethodOffsets Methods;
}
#endif