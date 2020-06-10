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

	switch(MissionWorldName)
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
	weather.GetRain().SetLimits( 0.0 , 0.0 );
    weather.GetOvercast().SetLimits( 0.0 , 0.0 );
    weather.GetFog().SetLimits( 0.0 , 0.01 );

    weather.GetOvercast().SetForecastChangeLimits( 0.0, 0.1 );
    weather.GetRain().SetForecastChangeLimits( 0.0, 0.0 );
    weather.GetFog().SetForecastChangeLimits( 0.0, 0.0 );

    weather.GetOvercast().SetForecastTimeLimits( 1800 , 1800 );
    weather.GetRain().SetForecastTimeLimits( 600 , 600 );
    weather.GetFog().SetForecastTimeLimits( 1800 , 1800 );
    
    weather.GetOvercast().Set( Math.RandomFloatInclusive(0.0, 0.3), 0, 0);
    weather.GetRain().Set( Math.RandomFloatInclusive(0.0, 0.0), 0, 0);
    weather.GetFog().Set( Math.RandomFloatInclusive(0.0, 0.1), 0, 0);
    
    weather.SetWindMaximumSpeed(15);
    weather.SetWindFunctionParams(0.1, 0.3, 50);    

	//! Init server central economy
	Hive ce = CreateHive();
	if ( ce )
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
class CustomMission: MissionServer
{
	// ------------------------------------------------------------
	// SetRandomHealth
	// ------------------------------------------------------------
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			int rndHlt = Math.RandomInt(55,100);
			itemEnt.SetHealth("","",rndHlt);
		}
	}

	void SetFullHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			itemEnt.SetHealth("","",100);
		}
	}
	
	override void OnInit()
	{
		ExpansionMissionModule missionModule;
		if ( Class.CastTo( missionModule, GetModuleManager().GetModule( ExpansionMissionModule ) ) )
		{
			missionModule.SetMissionConstructor( COMMissionConstructor );
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

	void GivePlayerItem(PlayerBase player, string slot, string className){
		EntityAI entity = player.FindAttachmentBySlotName(slot);
		if (entity && entity.ClassName()){
			// Print("Deleting "+entity);
			GetGame().ObjectDelete(entity);	
		}
		 
		player.GetInventory().CreateInInventory(className);
	}

	void GivePlayerSet(PlayerBase player, string kit[]){
			GivePlayerItem(player, "Body", kit[0]);	
			GivePlayerItem(player, "Pants", kit[1]);
			GivePlayerItem(player, "Shoulder1", kit[2]);
	}

	void PopulateItem(string slot, string items[]){
		EntityAI entity = player.FindAttachmentBySlotName(slot);
		for (int i=0; i< sizeof(items);i++){
			entity.GetInventory().CreateInInventory(items[i]);	
		}
		// ItemBase.Cast() ?? 
	}

	// ------------------------------------------------------------
	// Override StartingEquipSetup
	// ------------------------------------------------------------
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		if ( GetExpansionSettings() && GetExpansionSettings().GetSpawn() && GetExpansionSettings().GetSpawn().StartingGear.UseStartingGear )
		{
			Print("DEBUG: Starting Equipment Setup...")
			
			if (player && player.GetIdentity()) {
				//todo maybe 2D Array of ID + Gear Set
				// string id = player.GetIdentity().GetPlainId() 		//Steam ID
				string id = player.GetIdentity().GetId()				//DayZ ID
				string greengo = "I902fiOMut2MxacJJyYZxMLWdLmNynmd9xjJq-ud6IQ="
				string me = "yNWKGTL0KUvmYS-8Kk-DNhEonqcKIGSOmIVziUjav2M="
				
				switch(id) {
					//Todo define standard for "Kit" i.e. Top is always 0, bottoms always 1, etc etc
					case greengo:
						//TODO Greengo's Gear.
					break;
					case me:
						string dualKit[] = {
							"DSC_Sol_Hoodie_Black",
							"DSC_Black_Pants", 
							"A2WM110_black", 
							"A2Suppressor", 
							"A2WM110_mag",
							"M68Optic", 
							"Battery9V"
							//TODO BOOTS, GLOVES, HELMET,
						};
						player.RemoveAllItems();
						player.GetSlotsCountCorrect()
						GivePlayerItem(player, "Body", dualKit[0]);
						GivePlayerItem(player, "Pants", dualKit[1]);
						GivePlayerItem(player, "Shoulder1", dualKit[2]);
						PopulateItem("body", {dualKit[3], dualKit[4],  dualKit[4],  dualKit[4],  dualKit[5],  dualKit[6] });

					break;
					default: 
					SetStartingGear(player);
				}
			} else {
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
			
			if ( itemTop )
			{
				itemEnt = itemTop.GetInventory().CreateInInventory("Rag");
				if ( Class.CastTo(itemBs, itemEnt ) )
					itemBs.SetQuantity(4);

				SetRandomHealth(itemEnt);
				
				itemEnt = itemTop.GetInventory().CreateInInventory("RoadFlare");
				SetRandomHealth(itemEnt);
				
				rand = Math.RandomFloatInclusive(0.0, 1.0);
				if ( rand < 0.35 )
					itemEnt = player.GetInventory().CreateInInventory("Apple");
				else if ( rand > 0.65 )
					itemEnt = player.GetInventory().CreateInInventory("Pear");
				else
					itemEnt = player.GetInventory().CreateInInventory("Plum");
			
				SetRandomHealth(itemEnt);
			}
		}
	}
}


Mission CreateCustomMission(string path)
{
	return new CustomMission();
}