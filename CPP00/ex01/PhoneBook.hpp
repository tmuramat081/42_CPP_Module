#include "Contact.hpp"

/**
 * @brief 電話帳
 * 
 */
class PhoneBook {

    private:
        Contact contacts[8];

    public:
        void menu();
        void create_contact(Contact contact);
        void delete_contact();

};