#include <iostream>
#include <vector>
#include <random>

#define SIRKA 5
#define VYSKA 5
#define SMERY {'N', 'S', 'E', 'W'}

std::random_device rd;
std::mt19937 gen(rd());

struct Kurzor {
    int x;
    int y;
    // Kurzor(int x, int y) : x(x), y(y) {} // konstruktor
};

Kurzor kurzor;

void suradnicePreKurzor(void) {
    auto randomInt = [] (int min, int max) {
        return std::uniform_int_distribution<int>(min, max);
    };

    kurzor.x = randomInt(0, SIRKA - 1)(gen);
    kurzor.y = randomInt(0, VYSKA - 1)(gen);
}

struct Bod {
    int x;
    int y;
    char smer;
    bool navstiveny = false;

    Bod(int x, int y) : x(x), y(y) {}

    void nastavSmer(char smer) {
        this->smer = smer;
    }
};

class Bludisko {
    private:
        std::vector<std::vector<Bod>> body;

    public:
        Bludisko(){
            vytvorBody();
        }
        
        // ~ Bludisko() {} //dekonstruktor
        void vytvorBody(void) {
            for (int i = 0; i < VYSKA; i++) {
                std::vector<Bod> riadok;
                for (int j = 0; j < SIRKA; j++) {
                    // vytvori bod na suradniciach x, y so smerom N a prida ho do riadku
                    riadok.emplace_back(j, i);
                }
                body.push_back(riadok);
            }
        }

        void vypisBody(void) {
            for (const std::vector<Bod> riadok : body){
                for (const Bod bod : riadok){
                    std::cout<< "(" << bod.x << ", " << bod.y << ", " << bod.smer << ") ";
                }
                std::cout << std::endl;
            }

            std::cout << "Kurzor: (" << kurzor.x << ", " << kurzor.y << ")" << std::endl;
        }

        inline void zmenSmerBodu(int x, int y, char smer) {
            body[y][x].nastavSmer(smer);
        }

        inline void navstivBod(int x, int y) {
            body[y][x].navstiveny = true;
        }

        std::vector<char, int> zmenSmerPreKurzor(void) {
            int n[2] = {-1, 1};
            int index = std::uniform_int_distribution<int>(0, 1)(gen);
            // return {'a', n[index]};           
        }

        void nastavSmerBodov(void) {
            int vsetkyBody = SIRKA * VYSKA;
            int nastaveneBody = 0;
            std::vector<int[2]> minulePozicie = {{kurzor.x, kurzor.y}}; 

            do
            {
                
            } while (vsetkyBody != nastaveneBody);
            
        }
};

int main() {
    Bludisko bludisko;
    suradnicePreKurzor();
    bludisko.vypisBody();
    return 0;
}