/**
 * init.c
 *
 * DayZ Expansion Mod
 * www.dayzexpansion.com
 * © 2020 DayZ Expansion Mod Team
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
 * To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
 *
*/
#include "$CurrentDir:\\mpmissions\\Expansion.ChernarusPlusGloom\\expansion\\ExpansionObjectSpawnTools.c"
#include "$CurrentDir:\\mpmissions\\Expansion.ChernarusPlusGloom\\expansion\\missions\\MissionConstructor.c"

void main()
{
	bool loadTraderObjects = false;
	bool loadTraderNPCs = false;

	string MissionWorldName = "empty";
	GetGame().GetWorldName(MissionWorldName);

	switch (MissionWorldName)
	{
	case "ChernarusPlusGloom":
	{
		MissionWorldName = "ChernarusPlus";
		break;
	}
	case "enochGloom":
	{
		MissionWorldName = "enoch";
		break;
	}
	}

	if (MissionWorldName != "empty")
	{
		//! Spawn mission objects and traders
		FindMissionFiles(MissionWorldName, loadTraderObjects, loadTraderNPCs);
	}

	//! Returning weather class reference
	Weather weather = g_Game.GetWeather();

	//! Disable weather controller from mission
	weather.MissionWeather(true);

	//! Setup weather propperties
	weather.GetRain().SetLimits(0.0, 0.0);
	weather.GetOvercast().SetLimits(0.0, 0.0);
	weather.GetFog().SetLimits(0.0, 0.01);

	weather.GetOvercast().SetForecastChangeLimits(0.0, 0.1);
	weather.GetRain().SetForecastChangeLimits(0.0, 0.0);
	weather.GetFog().SetForecastChangeLimits(0.0, 0.0);

	weather.GetOvercast().SetForecastTimeLimits(1800, 1800);
	weather.GetRain().SetForecastTimeLimits(600, 600);
	weather.GetFog().SetForecastTimeLimits(1800, 1800);

	weather.GetOvercast().Set(Math.RandomFloatInclusive(0.0, 0.3), 0, 0);
	weather.GetRain().Set(Math.RandomFloatInclusive(0.0, 0.0), 0, 0);
	weather.GetFog().Set(Math.RandomFloatInclusive(0.0, 0.1), 0, 0);

	weather.SetWindMaximumSpeed(15);
	weather.SetWindFunctionParams(0.1, 0.3, 50);

	//! Init server central economy
	Hive ce = CreateHive();
	if (ce)
		ce.InitOffline();

	//! Setup time and date
	int year, month, day, hour, minute;
	int reset_month = 9, reset_day = 20;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

/**@class		CustomExpansionMission
 * @brief		This class handle expansion serverside mission
 **/
class CustomMission : MissionServer
{
	// ------------------------------------------------------------
	// SetRandomHealth
	// ------------------------------------------------------------
	void SetRandomHealth(EntityAI itemEnt)
	{
		if (itemEnt)
		{
			int rndHlt = Math.RandomInt(55, 100);
			itemEnt.SetHealth("", "", rndHlt);
		}
	}

	void SetFullHealth(EntityAI itemEnt)
	{
		if (itemEnt)
		{
			itemEnt.SetHealth("", "", 100);
		}
	}

	override void OnInit()
	{
		ExpansionMissionModule missionModule;
		if (Class.CastTo(missionModule, GetModuleManager().GetModule(ExpansionMissionModule)))
		{
			missionModule.SetMissionConstructor(COMMissionConstructor);
		}

		super.OnInit();
	}

	// ------------------------------------------------------------
	// Override PlayerBase CreateCharacter
	// ------------------------------------------------------------
	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");
		Class.CastTo(m_player, playerEnt);

		GetGame().SelectPlayer(identity, m_player);

		return m_player;
	}

	void GivePlayerItem(PlayerBase player, string slot, string className)
	{
		EntityAI entity = player.FindAttachmentBySlotName(slot);
		if (entity && entity.ClassName())
		{
			// Print("Deleting "+entity);
			GetGame().ObjectDelete(entity);
		}
		if (slot == "Shoulder1")
		{
			// player.SetQuickBarEntityShortcut(entity, 3, true)
		}
		else if (slot == "Shoulder2")
		{
			// player.SetQuickBarEntityShortcut(entity, 4, true)
		}

		player.GetInventory().CreateInInventory(className);
	}

	//ASK LARS ABOUT THESE PARSING STRING ARRAYS IN C IS AWFUl

	void GivePlayerSet(PlayerBase player, string[] kit)
	{
		GivePlayerItem(player, "Body", kit[0]);
		GivePlayerItem(player, "Pants", kit[1]);
		GivePlayerItem(player, "Shoulder1", kit[2]);
	}

	void PopulateItem(PlayerBase player, string slot, string[] items)
	{
		EntityAI entity = player.FindAttachmentBySlotName(slot);
		for (int i = 0; i < 10; i++)
		{
			if (items[i] != "")
			{
				entity.GetInventory().CreateInInventory(items[i]);
			}
			else
			{
				break;
			}
			// GetRPCManager ().AddRPC ("Mission", "ReloadClient", this, SingleplayerExecutionType.Both); //Server / Client / Both
		}
		// ItemBase.Cast() ??
	}

	void AddAttachments(PlayerBase player, bool shoulder, string[] attachments)
	{
		// Shoulder1 / Shoulder2 or Shoulder / Melee ???
		string weaponSlot = "shoulder";
		if (!shoulder)
		{
			weaponSlot = "melee";
		}
		Print(player.GetIdentity().GetPlainId());

		EntityAI weapon = player.FindAttachmentBySlotName(weaponSlot);

		for (int i = 0; i < 10; i++)
		{
			if (attachments[i] != "")
			{
				weapon.GetInventory().CreateAttachment(attachments[i]);
			}
			else
			{
				break;
			}
		}
		// "Battery9V"
		if (weapon.FindAttachmentBySlotName("weaponOptics"))
		{
			EntityAI optics = weapon.FindAttachmentBySlotName("weaponOptics");
			if (optics)
			{
				optics.GetInventory().CreateAttachment("Battery9V");
			}
		}
	}

	void CustomPlayerGear(PlayerBase player)
	{
		//todo maybe 2D Array of ID + Gear Set
		//string id = player.GetIdentity().GetPlainId() 		//Steam ID
		string id = player.GetIdentity().GetId() //DayZ ID
					string greengo = "I902fiOMut2MxacJJyYZxMLWdLmNynmd9xjJq-ud6IQ=";
		string me = "yNWKGTL0KUvmYS-8Kk-DNhEonqcKIGSOmIVziUjav2M=";

		switch (id)
		{
		//Todo define standard for "Kit" i.e. Top is always 0, bottoms always 1, etc etc
		case greengo:
			//TODO Greengo's Gear.
			break;
		case me:
			string dualKit[] = {
				"DSC_Sol_Hoodie_Black", //1 Body
				"DSC_Black_Pants",		//2 Pants
				"A2WM110_black",		//3

				// "Head",
				// "Shoulder",
				// "Melee",
				// "Headgear",
				// "Mask",
				// "Eyewear",
				// "Hands",
				// "LeftHand",
				// "Gloves",
				// "Armband",
				// "Vest",
				// "Body",
				// "Back",
				// "Hips",
				// "Legs",
				// "Feet"
			};
			string dualAttachments[] = {
				"A2Suppressor",
				"M68Optic",
				"A2WM110_mag",
			};
			player.RemoveAllItems();

			GivePlayerItem(player, "Body", dualKit[0]);
			GivePlayerItem(player, "Pants", dualKit[1]);
			GivePlayerItem(player, "Shoulder", dualKit[2]);

			string attachments[10] = {dualAttachments[0], dualAttachments[1]};
			AddAttachments(player, true, attachments);
			string items[10] = {dualAttachments[2], dualAttachments[2], dualAttachments[2]};
			PopulateItem(player, "Body", items);

			break;
		default:
			SetStartingGear(player);
		}
	}

	// ------------------------------------------------------------
	// Override StartingEquipSetup
	// ------------------------------------------------------------
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		if (GetExpansionSettings() && GetExpansionSettings().GetSpawn() && GetExpansionSettings().GetSpawn().StartingGear.UseStartingGear)
		{
			Print("DEBUG: Starting Equipment Setup...");

			if (player && player.GetIdentity())
			{
				CustomPlayerGear(player);
			}
			else
			{
				SetStartingGear(player);
			}
		}
		else
		{
			EntityAI itemTop;
			EntityAI itemEnt;
			ItemBase itemBs;
			float rand;

			itemTop = player.FindAttachmentBySlotName("Body");

			if (itemTop)
			{
				itemEnt = itemTop.GetInventory().CreateInInventory("Rag");
				if (Class.CastTo(itemBs, itemEnt))
					itemBs.SetQuantity(4);

				SetRandomHealth(itemEnt);

				itemEnt = itemTop.GetInventory().CreateInInventory("RoadFlare");
				SetRandomHealth(itemEnt);

				rand = Math.RandomFloatInclusive(0.0, 1.0);
				if (rand < 0.35)
					itemEnt = player.GetInventory().CreateInInventory("Apple");
				else if (rand > 0.65)
					itemEnt = player.GetInventory().CreateInInventory("Pear");
				else
					itemEnt = player.GetInventory().CreateInInventory("Plum");

				SetRandomHealth(itemEnt);
			}
		}
	}
}

Mission
CreateCustomMission(string path)
{
	return new CustomMission();
}