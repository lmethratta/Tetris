#include <iostream>

struct mutant {
    unsigned int mutant_id_number;
    char* last_name;
    struct {
        char zip_code[ 6 ];
    } personal, *personal_ptr = &personal;
} mutant_record, *mutant_ptr = & mutant_record, all_records[5];

int main() {
    // Part 1

    // mutant_record.mutant_id_number;
    // (*mutant_ptr).mutant_id_number;
    // mutant_record.last_name;
    // (*mutant_ptr).last_name;
    // mutant_record.personal.zip_code;
    // (*mutant_ptr).(*personal_ptr).zip_code;


    // Part 2

    // 2 Errors, from one mistake
    // (*personal_ptr) was incorrect, needed to access personal_ptr then dereference.
    mutant_record.mutant_id_number;
    (*mutant_ptr).mutant_id_number;
    mutant_record.last_name;
    (*mutant_ptr).last_name;
    mutant_record.personal.zip_code;
    (*(*mutant_ptr).personal_ptr).zip_code;

    // Part 3

    all_records[0].mutant_id_number = 0;
    all_records[0].last_name = "Smith";
    all_records[0].personal.zip_code[0] = '1';
    all_records[0].personal.zip_code[1] = '1';
    all_records[0].personal.zip_code[2] = '1';
    all_records[0].personal.zip_code[3] = '1';
    all_records[0].personal.zip_code[4] = '1';
    all_records[0].personal.zip_code[5] = '1';

    all_records[1].mutant_id_number = 1;
    all_records[1].last_name = "Wiliams";
    all_records[1].personal.zip_code[0] = '2';
    all_records[1].personal.zip_code[1] = '2';
    all_records[1].personal.zip_code[2] = '2';
    all_records[1].personal.zip_code[3] = '2';
    all_records[1].personal.zip_code[4] = '2';
    all_records[1].personal.zip_code[5] = '2';

    all_records[2].mutant_id_number = 2;
    all_records[2].last_name = "Daniels";
    all_records[2].personal.zip_code[0] = '3';
    all_records[2].personal.zip_code[1] = '3';
    all_records[2].personal.zip_code[2] = '3';
    all_records[2].personal.zip_code[3] = '3';
    all_records[2].personal.zip_code[4] = '3';
    all_records[2].personal.zip_code[5] = '3';

    all_records[3].mutant_id_number = 3;
    all_records[3].last_name = "Porter";
    all_records[3].personal.zip_code[0] = '4';
    all_records[3].personal.zip_code[1] = '4';
    all_records[3].personal.zip_code[2] = '4';
    all_records[3].personal.zip_code[3] = '4';
    all_records[3].personal.zip_code[4] = '4';
    all_records[3].personal.zip_code[5] = '4';

    all_records[4].mutant_id_number = 4;
    all_records[4].last_name = "Dyer";
    all_records[4].personal.zip_code[0] = '5';
    all_records[4].personal.zip_code[1] = '5';
    all_records[4].personal.zip_code[2] = '5';
    all_records[4].personal.zip_code[3] = '5';
    all_records[4].personal.zip_code[4] = '5';
    all_records[4].personal.zip_code[5] = '5';

    std::cout << all_records[0].mutant_id_number << ", " << all_records[0].last_name << ", " << all_records[0].personal.zip_code << "\n";
    std::cout << all_records[1].mutant_id_number << ", " << all_records[1].last_name << ", " << all_records[1].personal.zip_code << "\n";
    std::cout << all_records[2].mutant_id_number << ", " << all_records[2].last_name << ", " << all_records[2].personal.zip_code << "\n";
    std::cout << all_records[3].mutant_id_number << ", " << all_records[3].last_name << ", " << all_records[3].personal.zip_code << "\n";
    std::cout << all_records[4].mutant_id_number << ", " << all_records[4].last_name << ", " << all_records[4].personal.zip_code << "\n\n";

    mutant many_records[5];
    mutant *p;

    p = many_records;

    (*p).mutant_id_number = 0;
    (*p).last_name = "MUTANT_01";
    (*p).personal.zip_code[0] = '1';
    (*p).personal.zip_code[1] = '2';
    (*p).personal.zip_code[2] = '3';
    (*p).personal.zip_code[3] = '4';
    (*p).personal.zip_code[4] = '5';
    (*p).personal.zip_code[5] = '6';

    (*(p + 1)).mutant_id_number = 1;
    (*(p + 1)).last_name = "MUTANT_02";
    (*(p + 1)).personal.zip_code[0] = '1';
    (*(p + 1)).personal.zip_code[1] = '2';
    (*(p + 1)).personal.zip_code[2] = '3';
    (*(p + 1)).personal.zip_code[3] = '4';
    (*(p + 1)).personal.zip_code[4] = '5';
    (*(p + 1)).personal.zip_code[5] = '6';

    (*(p + 2)).mutant_id_number = 2;
    (*(p + 2)).last_name = "MUTANT_03";
    (*(p + 2)).personal.zip_code[0] = '1';
    (*(p + 2)).personal.zip_code[1] = '2';
    (*(p + 2)).personal.zip_code[2] = '3';
    (*(p + 2)).personal.zip_code[3] = '4';
    (*(p + 2)).personal.zip_code[4] = '5';
    (*(p + 2)).personal.zip_code[5] = '6';

    (*(p + 3)).mutant_id_number = 3;
    (*(p + 3)).last_name = "MUTANT_04";
    (*(p + 3)).personal.zip_code[0] = '1';
    (*(p + 3)).personal.zip_code[1] = '2';
    (*(p + 3)).personal.zip_code[2] = '3';
    (*(p + 3)).personal.zip_code[3] = '4';
    (*(p + 3)).personal.zip_code[4] = '5';
    (*(p + 3)).personal.zip_code[5] = '6';

    (*(p + 4)).mutant_id_number = 4;
    (*(p + 4)).last_name = "MUTANT_05";
    (*(p + 4)).personal.zip_code[0] = '1';
    (*(p + 4)).personal.zip_code[1] = '2';
    (*(p + 4)).personal.zip_code[2] = '3';
    (*(p + 4)).personal.zip_code[3] = '4';
    (*(p + 4)).personal.zip_code[4] = '5';
    (*(p + 4)).personal.zip_code[5] = '6';
    

    std::cout << (*p).mutant_id_number << ", " << (*p).last_name << ", " << (*p).personal.zip_code << "\n";
    std::cout << (*(p + 1)).mutant_id_number << ", " << (*(p + 1)).last_name << ", " << (*(p + 1)).personal.zip_code << "\n";
    std::cout << (*(p + 2)).mutant_id_number << ", " << (*(p + 2)).last_name << ", " << (*(p + 2)).personal.zip_code << "\n";
    std::cout << (*(p + 3)).mutant_id_number << ", " << (*(p + 3)).last_name << ", " << (*(p + 3)).personal.zip_code << "\n";
    std::cout << (*(p + 4)).mutant_id_number << ", " << (*(p + 4)).last_name << ", " << (*(p + 4)).personal.zip_code << "\n";
    
    // Observations: make sure to remember that . operator is stronger than * operator. ALSO no idea how to inialize char array without doing it individually.
    // online suggest using a std::string or str_cpy but that is only in c I believe.

    return 0;
}