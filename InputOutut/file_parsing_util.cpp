// ============================================================================
// <copyright file="file_utils.cpp" company="VRK">
//     Copyright (c) Venkata 2022. All rights reserved.
// </copyright>
// ============================================================================


// header files

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdint>

// simulated cswi strings
#define CSWI_POS_ORIGIN_ORCAT_STR   "cswi_pos_origin_orcat"
#define CSWI_POS_ORIGIN_ORIDENT_STR "cswi_pos_origin_orident"
#define CSWI_POS_CTLNUM_STR         "cswi_pos_ctlnum"
#define CSWI_POS_STVAL_STR          "cswi_pos_stval"
#define CSWI_POS_Q_STR              "cswi_pos_q"
#define CSWI_POS_STSELD_STR         "cswi_pos_stseld"

// global variables for simulating read values from file in C++
// In real time project avoid using global variables.

std::uint8_t sim_cswi_pos_origin_orcat   = 0;
std::uint8_t sim_cswi_pos_origin_orident = 0;
std::uint8_t sim_cswi_pos_ctlnum         = 0;
std::uint8_t sim_cswi_pos_stval          = 0;
std::uint8_t sim_cswi_pos_q              = 0;
std::uint8_t sim_cswi_pos_stseld         = 0;

// global variables for simulating read values from file in C
// In real time project avoid using global variables.

unsigned char c_sim_cswi_pos_origin_orcat   = 0;
unsigned char c_sim_cswi_pos_origin_orident = 0;
unsigned char c_sim_cswi_pos_ctlnum         = 0;
unsigned char c_sim_cswi_pos_stval          = 0;
unsigned char c_sim_cswi_pos_q              = 0;
unsigned char c_sim_cswi_pos_stseld         = 0;

// forward function declartions.
void cswi_inputs_read();
void cswi_inputs_read_helper(std::string line, std::uint8_t& value);
void print_cswi_simulated_values();

void c_cswi_inputs_read();
void c_cswi_inputs_read_helper(char* line, unsigned char& value);


/**
     * @brief main function which reads each line from file using C and C++.
     * @param None
     * @value None.
     * @return zero.
*/
int main() {
    std::cout << "Hello World!\n";
    cswi_inputs_read();
    c_cswi_inputs_read();
    return 0;
}

/**
     * @brief Read CSWI input data from file using C++.
     * @param None.
     * @return None.
*/
void cswi_inputs_read() {
    
    try {
        std::ifstream file("file_parsing_input.txt");
        std::string line;
        while (std::getline(file, line)) {
            if (line.rfind("#", 0) == 0) { // check if line is comment
                continue;
            }
            else {
                if (line.find(CSWI_POS_ORIGIN_ORCAT_STR) != std::string::npos) {
                    cswi_inputs_read_helper(line, sim_cswi_pos_origin_orcat);                    
                }
                else if (line.find(CSWI_POS_ORIGIN_ORIDENT_STR) != std::string::npos) {
                    cswi_inputs_read_helper(line, sim_cswi_pos_origin_orident);
                }
                else if (line.find(CSWI_POS_CTLNUM_STR) != std::string::npos) {
                    cswi_inputs_read_helper(line, sim_cswi_pos_ctlnum);
                }
                else if (line.find(CSWI_POS_STVAL_STR) != std::string::npos) {
                    cswi_inputs_read_helper(line, sim_cswi_pos_stval);
                }
                else if (line.find(CSWI_POS_Q_STR) != std::string::npos) {
                    cswi_inputs_read_helper(line, sim_cswi_pos_q);
                }
                else if (line.find(CSWI_POS_STSELD_STR) != std::string::npos) {
                    cswi_inputs_read_helper(line, sim_cswi_pos_stseld);
                }
                else {
                    std::cout << "Substring is not present." << std::endl;
                }
            }           
        }
    }
    catch(...) {
        std::cout << "error in reading scl_cswi_input.txt" << std::endl;
    }
    print_cswi_simulated_values();
    return;
}

/**
     * @brief parses each line from file using C++.
     * @param line line read from file
     * @value out param value to be returned.
     * @return value.
*/
void cswi_inputs_read_helper(std::string line, std::uint8_t& value) {
    int equal_pos = line.find('=');
    if (equal_pos != std::string::npos) {
        std::stringstream sim_value(line.substr(equal_pos + 1));
        value = std::stoi(line.substr(equal_pos + 1));
    }
}

/**
     * @brief prints CSWI simulated values using C++.
     * @param None.
     * @return None.
*/
void print_cswi_simulated_values() {
    std::cout << "Following are simulated values for CSWI logical node." << std::endl;
    std::cout << "sim_cswi_pos_origin_orcat: " << (unsigned int)sim_cswi_pos_origin_orcat << std::endl;
    std::cout << "sim_cswi_pos_origin_orident: " << (unsigned int)sim_cswi_pos_origin_orident << std::endl;
    std::cout << "sim_cswi_pos_ctlnum: " << (unsigned int)sim_cswi_pos_ctlnum << std::endl;
    std::cout << "sim_cswi_pos_stval: " << (unsigned int)sim_cswi_pos_stval << std::endl;
    std::cout << "sim_cswi_pos_q: " << (unsigned int)sim_cswi_pos_q << std::endl;
    std::cout << "sim_cswi_pos_stseld: " << (unsigned int)sim_cswi_pos_stseld << std::endl;
}

/**
     * @brief Read CSWI input data from file using C.
     * @param None.
     * @return None.
*/
void c_cswi_inputs_read() {
    //read any text file from currect directory
    char const* const input_file_name = "file_parsing_input.txt";

    FILE* input_file;
    fopen_s(&input_file, input_file_name, "r");

    if (!input_file) {
        printf("\n Unable to open : %s ", input_file_name);
    }

    char line[500];
    memset(line, 0x00, sizeof(line));
   
    while (fgets(line, sizeof(line), input_file)) {
        line[strlen(line) - 1] = '\0';
        if (line[0] == '#') {
            continue;
        }
        else {
            if (strstr(line, CSWI_POS_ORIGIN_ORCAT_STR) != NULL) {
                c_cswi_inputs_read_helper(line, c_sim_cswi_pos_origin_orcat);
            }
            else if (strstr(line, CSWI_POS_ORIGIN_ORIDENT_STR) != NULL) {
                c_cswi_inputs_read_helper(line, c_sim_cswi_pos_origin_orident);
            }
            else if (strstr(line, CSWI_POS_CTLNUM_STR) != NULL) {
                c_cswi_inputs_read_helper(line, c_sim_cswi_pos_ctlnum);
            }
            else if (strstr(line, CSWI_POS_STVAL_STR) != NULL) {
                c_cswi_inputs_read_helper(line, c_sim_cswi_pos_stval);
            }
            else if (strstr(line, CSWI_POS_Q_STR) != NULL) {
                c_cswi_inputs_read_helper(line, c_sim_cswi_pos_q);
            }
            else if (strstr(line, CSWI_POS_STSELD_STR) != NULL) {
                c_cswi_inputs_read_helper(line, c_sim_cswi_pos_stseld);
            }
            else {
                std::cout << "Substring is not present." << std::endl;
            }
        }
    }
    
    fclose(input_file);
}

/**
     * @brief parses each line from file using C.
     * @param line line read from file
     * @value out param value to be returned.
     * @return value.
*/
void c_cswi_inputs_read_helper(char* line, unsigned char& value) {
    char* equal = strchr(line, '=');  
    int equal_pos = (int)(equal - line);
    int len_line = strlen(line);
    char temp_value[10];
    memset(temp_value, 0x00, sizeof(temp_value));
    strncpy_s(temp_value, line + equal_pos+1, len_line - equal_pos);
    value = atoi(temp_value);
    return;    
}