class CfgPatches
{
    class DSC_Gear
    {
        units[]=
        {
            "DSC_Hoodie",
            "DSC_Greengo_Jacket",
            "DSC_Black_Pants",
            "Sol_Hoodie_Black",
            "DSC_Jacket_Black",
            "DSC_Jacket_Black_no"
        };

        weapons[]={};
        requiredVersion=0.1;
        requiredAddons[]=
        {
            "DZ_Gear_Containers",   
            "DZ_Characters_Tops",
            "DZ_Characters_Vests",
            "DZ_Characters_Pants",
            "DZ_Characters_Shoes",
            "DZ_Characters_Headgear",
            "DZ_Characters_Masks",
            "DZ_Data"
        };
    };
};


class cfgVehicles
{
    class Hoodie_ColorBase;

    class DSC_Hoodie_Default : Hoodie_ColorBase
    {
        scope=2;
        displayName="DSC Hoodie";
        descriptionShort="A hoodie for professionals.";
        itemsCargoSize[]={7,6};     

        hiddenSelections[]=
        {
            "zbytek",
            "camoGround",
            "camoMale",
            "camoFemale"
        };

        hiddenSelectionsTextures[]=
        {
            "DSC_Pack\DSCGear\data\DSC_Hoodie.paa",
            "DSC_Pack\DSCGear\data\DSC_Hoodie.paa",
            "DSC_Pack\DSCGear\data\DSC_Hoodie.paa",
            "DSC_Pack\DSCGear\data\DSC_Hoodie.paa",
            "DSC_Pack\DSCGear\data\DSC_Hoodie.paa"
        };
    };

    class TrackSuitJacket_ColorBase;

    class DSC_Greengo_Jacket : TrackSuitJacket_ColorBase
    {
        scope=2;
        displayName="Greengos private jacket";
        descriptionShort="A jacket for Greengo.";
        itemsCargoSize[]={10,100};

        hiddenSelections[]=
        {
            "zbytek",
            "camoGround",
            "camoMale",
            "camoFemale"
        };

        hiddenSelectionsTextures[]=
        {
            "DSC_Pack\DSCGear\data\dsc_greengo_jacket.paa",
            "DSC_Pack\DSCGear\data\dsc_greengo_jacket.paa",
            "DSC_Pack\DSCGear\data\dsc_greengo_jacket.paa",
            "DSC_Pack\DSCGear\data\dsc_greengo_jacket.paa",
            "DSC_Pack\DSCGear\data\dsc_greengo_jacket.paa"
        };
    };

    class DSC_Jacket_Black : TrackSuitJacket_ColorBase
    {
        scope=2;
        displayName="Black jacket";
        descriptionShort="A nice black jacket.";
        itemsCargoSize[]={7,6};    
        hiddenSelections[]=
        {
            "zbytek",
            "camoGround",
            "camoMale",
            "camoFemale"
        };

        hiddenSelectionsTextures[]=
        {
            "DSC_Pack\DSCGear\data\dsc_jacket_black.paa",
            "DSC_Pack\DSCGear\data\dsc_jacket_black.paa",
            "DSC_Pack\DSCGear\data\dsc_jacket_black.paa",
            "DSC_Pack\DSCGear\data\dsc_jacket_black.paa",
            "DSC_Pack\DSCGear\data\dsc_jacket_black.paa"
        };
    };

    class DSC_Jacket_Black_no : TrackSuitJacket_ColorBase
    {
        scope=2;
        displayName="Black Jacket (Norwegian)";
        descriptionShort="A nice black jacket, with the norwegian flag.";
        itemsCargoSize[]={7,6};

        hiddenSelections[]=
        {
            "zbytek",
            "camoGround",
            "camoMale",
            "camoFemale"
        };

        hiddenSelectionsTextures[]=
        {
            "DSC_Pack\DSCGear\data\dsc_jacket_black_no.paa",
            "DSC_Pack\DSCGear\data\dsc_jacket_black_no.paa",
            "DSC_Pack\DSCGear\data\dsc_jacket_black_no.paa",
            "DSC_Pack\DSCGear\data\dsc_jacket_black_no.paa",
            "DSC_Pack\DSCGear\data\dsc_jacket_black_no.paa"
        };
    };

    
    class CargoPants_ColorBase;

    class DSC_Black_Pants : CargoPants_ColorBase
    {
        scope=2;
        displayName="DSC Black Pants";
        descriptionShort="A nice pair of black pants.";
        itemsCargoSize[]={6,5};

        hiddenSelections[]=
        {
            "zbytek",
            "camoGround",
            "camoMale",
            "camoFemale"
        };

        hiddenSelectionsTextures[]=
        {
            "DSC_Pack\DSCGear\data\dsc_pants_black.paa",
            "DSC_Pack\DSCGear\data\dsc_pants_black.paa",
            "DSC_Pack\DSCGear\data\dsc_pants_black.paa",
            "DSC_Pack\DSCGear\data\dsc_pants_black.paa",
            "DSC_Pack\DSCGear\data\dsc_pants_black.paa"
        };
    };

    class DSC_Sol_Hoodie_Black : Hoodie_ColorBase
    {
        scope=2;
        displayName="Solidarity Hoodie";
        descriptionShort="A hoodie for revolutionaries.";
        itemsCargoSize[]={10,100};

        hiddenSelections[]=
        {
            "zbytek",
            "camoGround",
            "camoMale",
            "camoFemale"
        };

        hiddenSelectionsTextures[]=
        {
            "DSC_Pack\DSCGear\data\DSC_SOL_hoodie_black.paa",
            "DSC_Pack\DSCGear\Data\DSC_SOL_hoodie_black.paa",
            "DSC_Pack\DSCGear\Data\DSC_SOL_hoodie_black.paa",
            "DSC_Pack\DSCGear\Data\DSC_SOL_hoodie_black_f.paa",
            "DSC_Pack\DSCGear\Data\DSC_SOL_hoodie_black.paa"
        };
    };

    class M65Jacket_ColorBase;  

    class DSC_M65_Jacket_M90 : M65Jacket_ColorBase
    {
        scope=2;
        displayName="M65 Jacket (M90)";
        descriptionShort="For the wannabe Swedes in us all.";

        hiddenSelectionsTextures[]=
        {
            "DSC_Pack\DSCGear\data\m65_jacket_m90_co.paa",
            "DSC_Pack\DSCGear\Data\m65_jacket_m90_co.paa",
            "DSC_Pack\DSCGear\Data\m65_jacket_m90_co.paa",
            "DSC_Pack\DSCGear\Data\m65_jacket_m90_co.paa",
            "DSC_Pack\DSCGear\Data\m65_jacket_m90_co.paa"
        };
    }
};