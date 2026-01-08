/*
DSA‑FOCUSED QUICK REFERENCE: std::map and std::unordered_map
*/

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

/*
map vs unordered_map (DSA perspective)
-------------------------------------

std::map
 - Keys are stored in SORTED order
 - Implemented as a balanced BST (usually Red‑Black Tree)
 - insert / find / erase => O(log n)
 - Use when:
     * You need sorted order
     * You need lower_bound / upper_bound

std::unordered_map
 - Keys are NOT sorted
 - Implemented as a hash table
 - Average insert / find / erase => O(1)
 - Use when:
     * You only need fast lookup
     * Order does NOT matter (most frequency problems)
*/

// -------------------- Simple struct used as MAP VALUE (not key) --------------------
struct CityRecord {
    std::string name;
    uint64_t population;
    double latitude, longitude;
};

int main() {
    // =====================================================================
    // 1) WHY MAPS ARE NEEDED (compared to vector)
    // =====================================================================
    std::vector<CityRecord> cities;

    cities.push_back({"Melbourne", 5000000, 2.4, 9.4});
    cities.push_back({"Berlin", 6000000, 2.4, 9.4});
    cities.push_back({"Paris", 5000000, 2.4, 9.4});

    // Finding Berlin requires linear scan => O(n)
    for (const auto& city : cities) {
        if (city.name == "Berlin") {
            std::cout << "Berlin population: " << city.population << '\n';
            break;
        }
    }

    std::cout << '\n';

    // =====================================================================
    // 2) std::map BASIC USAGE (ordered)
    // =====================================================================
    std::map<std::string, CityRecord> cityMap;

    cityMap["Melbourne"] = {"Melbourne", 5000000, 2.4, 9.4};
    cityMap["Berlin"] = {"Berlin", 6000000, 2.4, 9.4};
    cityMap["Paris"] = {"Paris", 5000000, 2.4, 9.4};

    // Lookup by key => O(log n)
    std::cout << "Berlin population: "
              << cityMap["Berlin"].population << '\n';

    // Keys are sorted automatically
    for (const auto& [key, value] : cityMap) {
        std::cout << key << " -> " << value.population << '\n';
    }

    std::cout << '\n';

    // =====================================================================
    // 3) operator[] BEHAVIOUR (VERY IMPORTANT FOR DSA)
    // =====================================================================
    // If key exists -> returns reference to value
    CityRecord& berlin = cityMap["Berlin"];
    std::cout << berlin.name << " " << berlin.population << '\n';

    // If key does NOT exist -> INSERTS default value
    CityRecord& tokyo = cityMap["Tokyo"];

    // Default constructed value
    std::cout << "Tokyo: '" << tokyo.name << "' " << tokyo.population << '\n';

    // Modify directly through reference
    tokyo.name = "Tokyo";
    tokyo.population = 14000000;

    std::cout << '\n';

    // =====================================================================
    // 4) .find() (safe existence check)
    // =====================================================================
    auto it = cityMap.find("Paris");
    if (it != cityMap.end()) {
        std::cout << "Found Paris, population: "
                  << it->second.population << '\n';
    }

    // Preferred pattern in DSA (avoids accidental insertion)
    if (cityMap.find("Delhi") == cityMap.end()) {
        std::cout << "Delhi not found\n";
    }

    std::cout << '\n';

    // =====================================================================
    // 5) .at() (bounds‑checked access)
    // =====================================================================
    std::cout << cityMap.at("Melbourne").population << '\n';

    // .at() throws if key is missing (rarely used in contests)
    // cityMap.at("NonExistent"); // throws std::out_of_range

    std::cout << '\n';

    // =====================================================================
    // 6) Deletion
    // =====================================================================
    cityMap.erase("Paris");

    for (const auto& [key, value] : cityMap) {
        std::cout << key << " -> " << value.population << '\n';
    }

    std::cout << '\n';

    // =====================================================================
    // 7) std::unordered_map (DEFAULT CHOICE FOR DSA)
    // =====================================================================
    std::unordered_map<std::string, int> freq;

    // Typical frequency counting pattern
    freq["apple"]++;
    freq["banana"]++;
    freq["apple"]++;

    for (const auto& [key, value] : freq) {
        std::cout << key << " -> " << value << '\n';
    }

    // Fast existence check
    if (freq.find("orange") == freq.end()) {
        std::cout << "orange not present\n";
    }

    std::cout << '\n';

    // =====================================================================
    // 8) When to choose which? (DSA RULE OF THUMB)
    // =====================================================================
    /*
    Use unordered_map when:
     - Counting frequency
     - Checking existence
     - Order does not matter (MOST problems)

    Use map when:
     - You need sorted keys
     - You need lower_bound / upper_bound
     - You need to process keys in increasing order
    */

    return 0;
}
