#include <iostream>
#include <fstream>
#include <cmath>
#include <random>

#include "particle.hpp"
#include "integrators/omlyan_BA5B.hpp"
#include "force.hpp"
#include "potentials/free_diffusion.hpp"

#include <string>
int main(){

        double timestep = 0.0005;
        particle p;
        double steps = 100000; 
        p.r = 0;
        p.v = 0;
        p.f = 0;
        integrators::omelyan_BA5B integrate(timestep);
        integrate.add_potential(potentials::FreeDiffusion(p));
        integrate.update_force(p);
        std::cout<<"Time step size is "<< timestep <<std::endl;
        std::cout<<"Simulation start"<<std::endl;
        std::ofstream file;
        std::string fileformat(".txt");
        file.open(std::to_string(timestep)+fileformat);
        for (uint64_t i = 0; i < steps; ++i){
                integrate(p);
                file <<p.r<<std::endl;
        }
        file.close();
}
