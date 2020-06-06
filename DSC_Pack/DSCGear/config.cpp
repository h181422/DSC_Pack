class CfgPatches
{
    class DSC_Gear
    {
        units[]=
        {
            "DSC_Hoodie",
            "DSC_Greengo_Jacket",
            "DSC_Black_Pants",
            "Sol_Hoodie_Black"
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
        descriptionShort="A hoodie for Greengo.";
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
            "DSC_Pack\DSCGear\data\dsc_greengo_jacket.paa",
            "DSC_Pack\DSCGear\data\dsc_greengo_jacket.paa",
            "DSC_Pack\DSCGear\data\dsc_greengo_jacket.paa",
            "DSC_Pack\DSCGear\data\dsc_greengo_jacket.paa",
            "DSC_Pack\DSCGear\data\dsc_greengo_jacket.paa"
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

    class Sol_Hoodie_Black : Hoodie_ColorBase
    {
        scope=2;
        displayName="Solidarity Hoodie";
        descriptionShort="A hoodie for revolutionaries.";

        hiddenSelections[]=
        {
            "zbytek",
            "camoGround",
            "camoMale",
            "camoFemale"
        };

        hiddenSelectionsTextures[]=
        {
            "DSC_Pack\DSCGear\data\SOL_hoodie_black.paa",
            "DSC_Pack\DSCGear\Data\SOL_hoodie_black.paa",
            "DSC_Pack\DSCGear\Data\SOL_hoodie_black.paa",
            "DSC_Pack\DSCGear\Data\SOL_hoodie_black.paa",
            "DSC_Pack\DSCGear\Data\SOL_hoodie_black.paa"
        };
    };
};
