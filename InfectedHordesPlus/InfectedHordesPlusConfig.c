/*
  _    _               _         _____             __ _       
 | |  | |             | |       / ____|           / _(_)      
 | |__| | ___  _ __ __| | ___  | |     ___  _ __ | |_ _  __ _ 
 |  __  |/ _ \| '__/ _` |/ _ \ | |    / _ \| '_ \|  _| |/ _` |
 | |  | | (_) | | | (_| |  __/ | |___| (_) | | | | | | | (_| |
 |_|  |_|\___/|_|  \__,_|\___|  \_____\___/|_| |_|_| |_|\__, |
                                                         __/ |
                                                        |___/ 
*/

class InfectedHordesPlusConfig{
	private static const string SETTINGS_FILE = "$profile:\\InfectedHordesPlus.json";
	private int INT_MAX_ZOMBIES;     //Maximum amount of zombies
	private int INT_MIN_ZOMBIES;      //Minimum amount of zombies
	private int INT_INFECTEDHORDE_TIME;
	private int INT_INFECTEDHORDE_DESPAWNTIME;
	private int MAX_HORDES;

	private ref map<string, vector> m_HordePositions;

	void InfectedHordesPlusConfig(){
		m_HordePositions = new map<string, vector>;
	}

	void save(){
		JsonFileLoader<InfectedHordesPlusConfig>.JsonSaveFile(SETTINGS_FILE, this);
	}

	void load(){
		if(FileExist(SETTINGS_FILE)){
			JsonFileLoader<InfectedHordesPlusConfig>.JsonLoadFile(SETTINGS_FILE, this);
		} else{
			Print("No Config found, creating json for " + ClassName());
			createDefaults();
			save();
		}
	}

	void createDefaults(){
		INT_MAX_ZOMBIES      = 125; 
		INT_MIN_ZOMBIES      = 65; 
		INT_INFECTEDHORDE_TIME = 10;
		INT_INFECTEDHORDE_DESPAWNTIME = 100;
		MAX_HORDES = 10;

		m_HordePositions.Insert( "Severograd", "8428 0 12767" ); //string Name of location, vector centre position
        m_HordePositions.Insert( "Stary", "6046 0 7733" );
        m_HordePositions.Insert( "Vybor", "3784 0 8923" );
        m_HordePositions.Insert( "NWAFS", "4540 0 9645" );
		m_HordePositions.Insert( "NWAFC", "4823 0 10457" );
		m_HordePositions.Insert( "NWAFN", "4214 0 10977" );
        m_HordePositions.Insert( "Balota Air Strip", "4467 0 2496" );
        m_HordePositions.Insert( "Cherno City Centre", "6649 0 2710" );
        m_HordePositions.Insert( "Cherno West", "6374 0 2361" );
        m_HordePositions.Insert( "Cherno East", "7331 0 2850" );
        m_HordePositions.Insert( "Elektro West", "10077 0 1988" );
        m_HordePositions.Insert( "Elektro East", "10553 0 2313" );
        m_HordePositions.Insert( "Berezino City Centre", "12319 0 9530" );
        m_HordePositions.Insert( "Berezino South", "11991 0 9116" );
        m_HordePositions.Insert( "Berezino North", "12823 0 10078" );
        m_HordePositions.Insert( "Svetlojarsk", "13900 0 13258" );	
        m_HordePositions.Insert( "Zelenogorsk South", "2572 0 5105" );
        m_HordePositions.Insert( "Zelenogorsk North", "2741 0 5416" );
		m_HordePositions.Insert( "Novaya Petrovka", "3395 0 13013" );
		save();
	}

	vector getHordeZoneLocation(){
		int totalPossibleTowns  = m_HordePositions.Count();
		int oRandValue = Math.RandomIntInclusive(0,totalPossibleTowns);

		string TownName = m_HordePositions.GetKey(oRandValue);
		vector TownPosition = m_HordePositions.Get(TownName);
		return TownPosition;
	}
	
	int getHordeSpawnTime(){
		return INT_INFECTEDHORDE_TIME;
	}

	int getMaxInfectedCount(){
		return INT_MAX_ZOMBIES;
	}

	int getMinInfectedCount(){
		return INT_MIN_ZOMBIES;
	}

	int getMaxHordes(){
		return MAX_HORDES;
	}
	int getDespawnTime(){
		return INT_INFECTEDHORDE_DESPAWNTIME;
	}

	ref array<string> getZombieClasses(){
		return {
			"ZmbM_HermitSkinny_Beige","ZmbM_HermitSkinny_Black","ZmbM_HermitSkinny_Green","ZmbM_HermitSkinny_Red","ZmbM_FarmerFat_Beige","ZmbM_FarmerFat_Blue","ZmbM_FarmerFat_Brown",
			"ZmbM_FarmerFat_Green","ZmbF_CitizenANormal_Beige","ZmbF_CitizenANormal_Brown",
			"ZmbF_CitizenANormal_Blue","ZmbM_CitizenASkinny_Blue","ZmbM_CitizenASkinny_Brown",
			"ZmbM_CitizenASkinny_Grey","ZmbM_CitizenASkinny_Red","ZmbM_CitizenBFat_Blue","ZmbM_CitizenBFat_Red",
			"ZmbM_CitizenBFat_Green","ZmbF_CitizenBSkinny","ZmbM_PrisonerSkinny",
			"ZmbM_FirefighterNormal","ZmbM_FishermanOld_Blue","ZmbM_FishermanOld_Green",
			"ZmbM_FishermanOld_Grey","ZmbM_FishermanOld_Red","ZmbM_JournalistSkinny",
			"ZmbF_JournalistNormal_Blue","ZmbF_JournalistNormal_Green","ZmbF_JournalistNormal_Red","ZmbF_JournalistNormal_White",
			"ZmbM_ParamedicNormal_Blue","ZmbM_ParamedicNormal_Green","ZmbM_ParamedicNormal_Red",
			"ZmbM_ParamedicNormal_Black","ZmbF_ParamedicNormal_Blue","ZmbF_ParamedicNormal_Green",
			"ZmbF_ParamedicNormal_Red","ZmbM_HikerSkinny_Blue","ZmbM_HikerSkinny_Green","ZmbM_HikerSkinny_Yellow",
			"ZmbF_HikerSkinny_Blue","ZmbF_HikerSkinny_Grey","ZmbF_HikerSkinny_Green","ZmbF_HikerSkinny_Red",
			"ZmbM_HunterOld_Autumn","ZmbM_HunterOld_Spring","ZmbM_HunterOld_Summer","ZmbM_HunterOld_Winter",
			"ZmbF_SurvivorNormal_Blue","ZmbF_SurvivorNormal_Orange","ZmbF_SurvivorNormal_Red",
			"ZmbF_SurvivorNormal_White","ZmbM_SurvivorDean_Black","ZmbM_SurvivorDean_Blue","ZmbM_SurvivorDean_Grey",
			"ZmbM_PolicemanFat","ZmbF_PoliceWomanNormal",
			"ZmbM_PolicemanSpecForce","ZmbM_SoldierNormal",
			"ZmbM_usSoldier_normal_Woodland","ZmbM_usSoldier_normal_Desert","ZmbM_CommercialPilotOld_Blue",
			"ZmbM_CommercialPilotOld_Olive","ZmbM_CommercialPilotOld_Brown","ZmbM_CommercialPilotOld_Grey",
			"ZmbM_PatrolNormal_PautRev","ZmbM_PatrolNormal_Autumn","ZmbM_PatrolNormal_Flat","ZmbM_PatrolNormal_Summer",
			"ZmbM_JoggerSkinny_Blue","ZmbM_JoggerSkinny_Green","ZmbM_JoggerSkinny_Red","ZmbF_JoggerSkinny_Blue",
			"ZmbF_JoggerSkinny_Brown","ZmbF_JoggerSkinny_Green","ZmbF_JoggerSkinny_Red","ZmbM_MotobikerFat_Beige",
			"ZmbM_MotobikerFat_Black","ZmbM_MotobikerFat_Blue","ZmbM_VillagerOld_Blue","ZmbM_VillagerOld_Green",
			"ZmbM_VillagerOld_White","ZmbM_SkaterYoung_Blue","ZmbM_SkaterYoung_Brown","ZmbM_SkaterYoung_Green",
			"ZmbM_SkaterYoung_Grey","ZmbF_SkaterYoung_Brown","ZmbF_SkaterYoung_Striped","ZmbF_SkaterYoung_Violet",
			"ZmbF_DoctorSkinny","ZmbF_BlueCollarFat_Blue","ZmbF_BlueCollarFat_Green",
			"ZmbF_BlueCollarFat_Red","ZmbF_BlueCollarFat_White","ZmbF_MechanicNormal_Beige","ZmbF_MechanicNormal_Green",
			"ZmbF_MechanicNormal_Grey","ZmbF_MechanicNormal_Orange","ZmbM_MechanicSkinny_Blue","ZmbM_MechanicSkinny_Grey",
			"ZmbM_MechanicSkinny_Green","ZmbM_MechanicSkinny_Red","ZmbM_ConstrWorkerNormal_Beige",
			"ZmbM_ConstrWorkerNormal_Black","ZmbM_ConstrWorkerNormal_Green","ZmbM_ConstrWorkerNormal_Grey",
			"ZmbM_HeavyIndustryWorker","ZmbM_OffshoreWorker_Green","ZmbM_OffshoreWorker_Orange","ZmbM_OffshoreWorker_Red",
			"ZmbM_OffshoreWorker_Yellow","ZmbF_NurseFat","ZmbM_HandymanNormal_Beige",
			"ZmbM_HandymanNormal_Blue","ZmbM_HandymanNormal_Green","ZmbM_HandymanNormal_Grey","ZmbM_HandymanNormal_White",
			"ZmbM_DoctorFat","ZmbM_Jacket_beige","ZmbM_Jacket_black","ZmbM_Jacket_blue","ZmbM_Jacket_bluechecks",
			"ZmbM_Jacket_brown","ZmbM_Jacket_greenchecks","ZmbM_Jacket_grey","ZmbM_Jacket_khaki","ZmbM_Jacket_magenta","ZmbM_Jacket_stripes",
			"ZmbF_PatientOld","ZmbM_PatientSkinny","ZmbF_ShortSkirt_beige",
			"Zmb_WalkersF_ShortSkirt_black","ZmbF_ShortSkirt_brown","ZmbF_ShortSkirt_green","ZmbF_ShortSkirt_grey","ZmbF_ShortSkirt_checks",
			"ZmbF_ShortSkirt_red","ZmbF_ShortSkirt_stripes","ZmbF_ShortSkirt_white","ZmbF_ShortSkirt_yellow",
			"ZmbF_VillagerOld_Blue","ZmbF_VillagerOld_Green","ZmbF_VillagerOld_Red","ZmbF_VillagerOld_White","ZmbM_Soldier","ZmbM_SoldierAlice",
			"ZmbM_SoldierHelmet","ZmbM_SoldierVest","ZmbM_SoldierAliceHelmet","ZmbM_SoldierVestHelmet",
			"ZmbF_MilkMaidOld_Beige","ZmbF_MilkMaidOld_Black","ZmbF_MilkMaidOld_Green","ZmbF_MilkMaidOld_Grey",
			"ZmbM_priestPopSkinny","ZmbM_ClerkFat_Brown","ZmbM_ClerkFat_Grey","ZmbM_ClerkFat_Khaki","ZmbM_ClerkFat_White","ZmbF_Clerk_Normal_Blue","ZmbF_Clerk_Normal_White","ZmbF_Clerk_Normal_Green","ZmbF_Clerk_Normal_Red",
		};
	}
}
