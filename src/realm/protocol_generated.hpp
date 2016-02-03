enum { kSLoadZone = 2 };
enum { kSZoneState = 3 };
enum { kSEntitySpawn = 20 };
enum { kCEnterWorld = 2 };
enum { kSHello = 1 };
enum { kSEntityDespawn = 21 };
enum { kSEntityUpdate = 22 };
enum { kCHello = 1 };
enum { kCPlayerMovement = 4 };
enum { kCZoneLoaded = 3 };

struct SLoadZone {
    std::string	zoneName;
    SHA3_224	zoneRef;

    bool Decode(const uint8_t* buffer, size_t length);
    bool Encode(std::ostream& out);
};
struct SZoneState {
    struct Entity {
    uint32_t	eid;
    uint32_t	flags;
    std::string	name;
    glm::vec3	pos;
    glm::vec3	dir;
    };
    glm::vec3	playerPos;
    glm::vec3	playerDir;
    int32_t	playerEid;
    std::vector<Entity>	entities;

    bool Decode(const uint8_t* buffer, size_t length);
    bool Encode(std::ostream& out);
};
struct SEntitySpawn {
    struct Entity {
    uint32_t	eid;
    uint32_t	flags;
    std::string	name;
    glm::vec3	pos;
    glm::vec3	dir;
    };
    Entity	entity;

    bool Decode(const uint8_t* buffer, size_t length);
    bool Encode(std::ostream& out);
};
struct CEnterWorld {
    std::string	characterName;

    bool Decode(const uint8_t* buffer, size_t length);
    bool Encode(std::ostream& out);
};
struct SHello {
    std::vector<std::string>	characters;

    bool Decode(const uint8_t* buffer, size_t length);
    bool Encode(std::ostream& out);
};
struct SEntityDespawn {
    int32_t	eid;

    bool Decode(const uint8_t* buffer, size_t length);
    bool Encode(std::ostream& out);
};
struct SEntityUpdate {
    uint32_t	eid;
    glm::vec3	pos;
    glm::vec3	dir;
    glm::vec3	velocity;

    bool Decode(const uint8_t* buffer, size_t length);
    bool Encode(std::ostream& out);
};
struct CHello {
    SHA3_224	token;

    bool Decode(const uint8_t* buffer, size_t length);
    bool Encode(std::ostream& out);
};
struct CPlayerMovement {
    glm::vec3	pos;
    glm::vec3	dir;
    glm::vec3	velocity;

    bool Decode(const uint8_t* buffer, size_t length);
    bool Encode(std::ostream& out);
};
struct CZoneLoaded {
    bool Decode(const uint8_t* buffer, size_t length);
    bool Encode(std::ostream& out);
};
