/* 

    ***ENUM CLASS IMPLEMENTATIONS***

    ***AFTER DEFINING ENUM CLASSES, STRUCTS AND CLASSES ARE DEFINED IN THEIR RESPECTIVE FILES***

    ***WE STRIVE TO FOLLOW PRINCIPLES DEFINED BELOW***

    - Tries to avoid duplication and redundancy.
    - Functions should be nested
    - Fields should be nested
    - Structs should inherit from parent
    - Classes should inherit from parent

    ***DID YOU KNOW?***

    - Enum classes are used to define a set of named constants
    - Enum classes are strongly typed, meaning that the values of an enum class are not implicitly convertible to integers or other types
    - Enum classes are scoped, meaning that the names of the enumerators are not visible outside the enum class
    - Enum classes are used to improve code readability and maintainability

    ***THE 7 PRINCIPLES OF OOP***
    - Encapsulation
    - Abstraction
    - Inheritance
    - Polymorphism
    - Composition
    - Aggregation
    - Association

    ***SOLID PRINCIPLES***
    - Single Responsibility Principle (SRP)
    - Open/Closed Principle (OCP)
    - Liskov Substitution Principle (LSP)
    - Interface Segregation Principle (ISP)
    - Dependency Inversion Principle (DIP)

*/

    
/* HERE FOLLOWS THE MAINLOOP */
enum class MainLoop
{
    // Main loop states
    INIT,
    EVENT,
    UPDATE,
    CLEAN_AND_QUIT,
    ERROR,
};

/* HERE FOLLOWS THE GAME SCENES */
enum class GameState
{
    LOADING_GAME,
    PROLOUGUE,
    MAIN_MENU,
    SETTINGS,
    CREDITS,
    LOADING_SCENE,
    GAME_SCENE,
    ACHIEVEMENT,
    GAME_OVER,
    ERROR,
};

/* HERE FOLLOWS PLAYER MOVEMENT */
enum class PlayerManeuver
{
    // MOVEMENT
    IDLE,
    IN_AIR,
    JUMP,
    LAND,
    ROLL,
    RUN,
    SPRINT,
    // PARKOUR
    VAULT,
    LONG_VAULT,
    TALL_VAULT,
    CLIMB,
    TALL_CLIMB,
    HANG,
};

/* HERE FOLLOWS GAME SCENE TYPE */
enum class GameSceneType{

    DEFENSE,
    ATTACK,
    FIGHT,

    CHASE,
    ESCAPE,
    STEAL,
    ROB,
    HIDE,
    RACE,

    GAMBLE,
    TRADE,
    HIRE,
    BUY,
    SELL,

    SYNTHESIS,
    RESEARCH,
    INVESTIGATE,
    PHILOSOPHY,

    FREE_RUN,
};

/* HERE FOLLOWS GAME POPUPS */
enum class GamePopUp
{

    AQUISITION,
    DEAQUISITION,

    // WINNING CONDITIONS
    YOU_WOEN_THE_FIETE,
    YOU_ESCAEPED,
    YOU_ARRYVED_IN_TYME,
    YOU_ARRYVED_IN_TYME_WITHOUT_BEING_SEAN,
    // LOSING CONDITIONS
    THEY_WOEN,
    YOURE_TRAEPPED_NOUW,
    YOU_DYED,
};

/* HERE FOLLOWS IN-GAME CONDITION STATES */
enum class ConditionState {
    // VOLUME STATES
    GROWING,
    EXPANDING,
    WITHERING,
    SHRINKING,
    COLLAPSING,
    FADING,
    // REACTION STATES
    MELTING,
    EVAPORATING,
    FREEZING,
    CONDENSING,
    CRYSTALLIZING,
    DISSOLVING,
    DECOMPOSING,
    REACTING,
    COMBUSTING,
    // FIRE STATES
    BURNING,
    QUENCHING,
    // ACTIVE STATES
    UNDERGOING,
    TRANSFORMING,
    CHANGING,
    // BIOLOGICAL STATES
    MUTATING,
    EVOLVING,
    ADAPTING,
    REGENERATING,
    REPRODUCING,
};
/* HERE FOLLOWS OPEN ENVIRONMENTS*/
enum class OpenEnvironments
{
    LOWER_STRATA_DISTRICT,
    MIDDLE_STRATA_DISTRICT,
    UPPER_STRATA_DISTRICT,

};
/* HERE FOLLOWS LINEAR ENVIRONMENTS*/
enum class LinearEnvironments
{
    PRISON_YARD,
    PRISON_CELL,
    PRISON_SHOWER,
    PRISON_GYM,
    PRISON_CANTEEN,

    LABOUR_CAMP,

    PARK,
    SCHOOL,
    LIBRARY,
    SHOPPING_MALL,
    HOSPITAL,
    STADIUM,
    THEATER,
    MUSEUM,
    ZOO,
    AMUSEMENT_PARK,

    TRAFFIC_AREA,
};

/* HERE FOLLOWS THE CHEMISTRY RELATED */

enum class PeriodicTable
{
    HYDROGEN,
    HELIUM,
    LITHIUM,
    BERYLLIUM,
    BORON,
    CARBON,
    NITROGEN,
    OXYGEN,
    FLUORINE,
    NEON,
    SODIUM,
    MAGNESIUM,
    ALUMINUM,
    SILICON,
    PHOSPHORUS,
    SULFUR,
    CHLORINE,
    ARGON,
};

enum class ChemicalBond
{
    SINGLE_BOND,
    DOUBLE_BOND,
    TRIPLE_BOND,
    IONIC_BOND,
    COVALENT_BOND,
    POLAR_COVALENT_BOND,
    METALLIC_BOND,
};

enum class ChemicalState
{
    SOLID,
    LIQUID,
    GAS,
};

enum class PHScale
{
    ACIDIC,
    NEUTRAL,
    ALKALINE,
};

enum class ChemicalReaction
{
    REDUCTION,
    OXIDATION,
    NATURALIZATION,
};

enum class Acid
{
    SULFURIC_ACID,
    NITRIC_ACID,
    HYDROCHLORIC_ACID,
    ACETIC_ACID,
    PHOSPHORIC_ACID,
};

enum class Base
{
    SODIUM_BICARBONATE,
    SODIUM_HYDROXIDE,
    POTASSIUM_HYDROXIDE,
    CALCIUM_HYDROXIDE,
    MAGNESIUM_HYDROXIDE,
    AMMONIUM_HYDROXIDE,
};

enum class Solvent
{
    WATER,
    ETHANOL,
    ACETONE,
    METHANOL,
    ETHYL_ACETATE,
    ACETIC_ACID,
    HEXANE,
    BENZENE,
    TOLUENE,
    CHLOROFORM,
};

enum class Catalyst
{
    PLATINUM,
    PALLADIUM,
    NICKEL,
    IRIDIUM,
    RHODIUM,
    RUTHENIUM,
    OSMIUM,
    TUNGSTEN,
    MOLYBDENUM,
    TANTALUM,
};

enum class MoleculeType
{
    HORMONE,
    NEUROTRANSMITTER,
    INHIBITOR,
    TOXIN,
    PESTICIDE,
    ENZYME,
    PROTEIN,
    CARBOHYDRATE,
    LIPID,
    DISINFECTANT,
    ANTIBIOTIC,
    MUTAGEN,

};

/* HERE FOLLOWS MEDICAL CONDITIONS AND MEDICINES */

enum class DrugType
{
    STIMULANT,
    DEPRESSANT,
    HALLUCINOGEN,
    ANALGESIC,
    ANESTHETIC,
    ANTIDEPRESSANT,
    ANTIPSYCHOTIC,
    ANXIOLYTIC,
    SEDATIVE,
    TRANQUILIZER,
    VACCINE,
    ANTIBODY,
};

/* Character Enum Classes */

enum class CharacterAge
{
    BABY,
    CHILD,
    TEENAGER,
    ADULT,
    OLD_ADULT,
    SENIOR,
};

enum class CharacterSex
{
    MALE,
    FEMALE,
    TRANS,
    NON_BINARY,
};

enum class CharacterOccupation
{
    // Closer implementations
    LABOURER,
    GUARD,
    SCIENTIST,
    ENGINEER,
    ARCHITECT,
    DOCTOR,
    AGENT,

    // Other occupations
    UNEMPLOYED,
    STUDENT,
    POLICE_OFFICER,
    FIRE_FIGHTER,
    PARAMEDIC,
    NURSE,
    TEACHER,
    ARTIST,
    MUSICIAN,
    WRITER,

};

enum class CharacterMood
{

};

enum class CharacterMedicalCondition
{
    HEALTHY,
    ANXIETY,
    DEPRESSION,
    SCHIZOPHRENIA,
    BIPOLAR_DISORDER,
    PTSD,
    OCD,
    ADHD,
    AUTISM,
    EATING_DISORDER,
    ADDICTION,
    INSOMNIA,
};

/* IN-GAME PRE POST DATETIME CALENDAR RELATED */

enum class GameTime
{
    // TIME UNITS
    GAME_DAY,
    GAME_HOUR,
    GAME_MINUTE,
    GAME_SECOND,
    GAME_MILLISECOND,
    // 24-HOUWER CLOKUE
    MEADNYTE, // 00:00
    DARKTIM,
    FOGSUN, // 05:00
    SUNBRITE, // 07:30
    WAKETIM, // 10:00
    CLOUSEND, // 14:00
    BEGENDEY, // 17:00
    DUSK,
    // CLOSE-BY UNITS
    BEFORE,
    YESTERDAY,
    TODAY,
    TOMORROW,
    AFTER,
    // D/W/S/Y UNITS OF MEASURING TYME
    DEYNITES,
    WAEKLONS,
    SEESONIE,
    YAREACS,
    // DEYNITES OF THE WAEKLON
    INITIME,
    NEXTHYME,
    MIDTHEYM,
    FOURDEYTE,
    FRAEDEY,
    TWYENITE,
    DEYNITE,
    // NEW-YEAR
    NEW_YEAR,
    NEW_YEAR_EVE,
    NEW_YEAR_DAY,
    // SEASONS
    SPRING,
    SUMMER,
    AUTUMN,
    WINTER,
};
enum class GameTymePrefixe {
    // MATURITY
    INMATURAE,
    PREAMATURAE,
    YOUNG,
    RIPE,
    FRESH,
    MATURE,
    OLD,
    // STATE
    EARLY,
    MID,
    LATE,
    // STABLE PREFIXES
    NEKST,
    LAEST,
    PREVIEOUS,
    COURANTE,
    // EPOCHS
    PREHISTORIC,
    ANCIENT,
    CLASSICAL,
    MODERN,
    POEST_MOEDARN,
    // PHASES
    PREPARATION,
    INTRODUCTION,
    BEGINNING,
    MID_POINT,
    ALMOST_THERE,
    NEAR_END,
    A_POINT,
    FINISH,
    END,
    CONCLUSION,
    // SCORE
    BEHIND,
    AHEAD_OF,
    // POST SCORE
    TIME,
    SCHEDULE,
    PLAN,
    // JUST PREFIXES
    JUST_PASSED,
    JUST_FINISHED,
    JUST_STARTED,
    JUST_BEGUN,
    JUST_A_MOMENT,
    JUST_NOW,
    // PREFIXES
    THIS,
    SINCE,
    LAST,
    PAST,
    RECENT,
    // CONTINUING PREFIXES
    THEN,
    NOW,
    LATER,
    // CURRENT PRE-HISTORIC
    IN_THE_PAST,
    IN_THE_PAST_FUTURE,
    // CURRENT TIME
    RIGHT_NOW,
    AT_THIS_MOMENT,
    AT_THIS_TIME,
    // CURRENT PLAN
    IN_THE_FUTURE,
    IN_A_MOMENT,
    IN_A_WHILE,
    AS_PLANNED,
    AS_SCHEDULED,
    // PAST
    BEFOURE,
    SYNCE,
    PAEST,
    PASSÉ,
    // FUTURE
    LAETIR,
    UPCOMEING,
};

/* HERE FOLLOWS UI, IN-GAME GRAPHICS AND AUDIO */

enum class Direction
{
    BEHIND,
    ON_TOP,

    VERTICAL,
    HORIZONTAL,
    DIAGONAL,

    UPSTREAM,
    DOWNSTREAM,

    START,
    STOP,
    CHANGE_DIRECTION,
    AT_POINT,

    CORNER,
    CENTER,

    NORTH,
    NEAST,
    NWEST,
    WEST,
    EAST,
    SEAST,
    SWEST,
    SOUTH,

    DEGREES,
};

enum class PositionGraphic
{
    LAYER_DEPTH,
    LAYER_RANK,

    NORTH,
    NEAST,
    NWEST,
    WEST,
    EAST,
    SEAST,
    SWEST,
    SOUTH,

};

/* HERE FOLLOWS DESIGNS TO RENDER WITH SDL */

enum class Color
{
    RED,
    GREEN,
    BLUE,
    WHITE,
    BLACK,
    YELLOW,
    ORANGE,
    PURPLE,
    PINK,
    BROWN,
    GREY,
};

enum class Shape
{
    LINE,
    POINT,
    TRIANGLE,
    RECTANGLE,
    CIRCLE,
    CONE,
    CONTOUR,
};

enum class UIContext
{
    BUTTON,
    TEXT,
    IMAGE,
    SLIDER,
    CHECKBOX,
    RADIOBUTTON,
    DROPDOWN,
};

/* VERY IMPORTANT ENUM CLASS */

enum class GameData{
    // IN-GAME SAVE AND LOAD 
    
};

enum class CharacterStatus
{
    // HERE GOES CHARACTER STATUS
    /* Status of a character is initiated, usually in chain-reaction
    - should require a "reciever" Character class based object
    - possibility of multiple "recievers"
    - will ALWAYS activate in reponse to certian activity
    - such an activity can be self-induced, substance-induced, external-induced etc
    - e.g. Player currently NEAR_DEATH or Player*/

    /* ALIVE OR NOT */
    ALIVE,
    COMA,
    NEAR_DEATH,
    DEAD,

    /* AWAKE OR NOT */
    AWAKE,
    ASLEEP,
    COMA,

    /* AWARE OR NOT*/
    WALKING_IN_SLEEP,
    LOST_IN_FANTASIES,

    /* STATUS GRADE DEGREES */
    MINOR,
    AVERAGE,
    MAJOR,

    /* CAUSE OF STATUS */
    PHYSICAL_RESPONSE,
    ROUTINE,
    REFLEX,
    ALLERGY,


    /* PHYSICAL */
    ALERT,
    RELAXED,
    TIRED,
    EXHAUSTED,

    /* MENTAL */

    OPTIMISTIC,
    PESSIMISTIC,
    SCEPTIC,
    DISAPPOINTED,
    // These should be hard to host
    ABSTINENCE,
    SIDE_EFFECT,
    COME_DOWN,
    HUNGOVER,
    CRASH,

    SICK,
    ILL,
    SNEEZY,
    SNOTTY,
    COUGHING,

    PHYSICALLY_HURT,

    PSYCHOSIS,
    MANIA,
    HYPOCHONDRIA,

    STRESS,
    PARANOIA,
    SKEPCISM,
    FEAR,

    TRANQUILIZED,
    PARALYZED,

    INTOXICATION,
    STIMULANT,
    SEDATIVE,

    // Character Moods
    HAPPY,
    SAD,
    ANGRY,
    CONFUSED,
    SCARED,
    EXCITED,
    BORED,
    RELAXED,
    NERVOUS,
    CALM,

};

enum class CharacterTrait
{
    BRAVE,
    COWARDLY,
    HONEST,
    DISHONEST,
    LOYAL,
    BETRAYING,
    INTELLIGENT,
    DUMB,
    STRONG,
    WEAK,
    FAST,
    SLOW,
};

/* Faction related */

enum class Faction
{
    // Your faction
    THE_SILENCE,

    // Evil factions
    THE_CHEMICAL_SOCIETY,
    GUARDIANS_OF_THE_CHAIN,

    // Lower strata tribes
    SIMPLY_ARMED_RELATIONSHIPS,
    SHEPHERDS_OF_THE_APOCALYPSE,
    CARVERS_OF_HISTORY,
    A_WANDERERS_PEACE,
    THE_ROYAL_HONOR,

};



/* More enum classes to add such as blockchain hosted trading,
price of hired blades, taxi, insurances, political voting, bribing etc..
*/