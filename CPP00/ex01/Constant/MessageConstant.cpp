#include "MessageConstant.hpp"

const std::string MessageConstant::ENTER_COMMAND = ">> Enter a command (ADD, SEARCH, or EXIT)";
const std::string MessageConstant::ENTER_INDEX = ">> Enter a index (1-8)";
const std::string MessageConstant::CREATE_CHECK = ">> Register with this contact? (YES/NO)";
const std::string MessageConstant::CREATE_SUCCESS = "Contact registered.";
const std::string MessageConstant::EXIT_CHECK = ">> All contacts will be deleted. Are you sure ? (YES/NO)";
const std::string MessageConstant::EXIT_APP = "Existing the phonebook application.";
const std::string MessageConstant::Error::INVALID_COMMAND = "Invalid command";
const std::string MessageConstant::Error::NOT_EXIST_CONTACT = "The contact does not exist or has already been deleted.";
const std::string MessageConstant::Error::INVALID_LENGTH = "Invalid input. Please enter within 20 characters.";
const std::string MessageConstant::Error::INVALID_INPUT = "Invalid input. Please try again. (1-8)";
const std::string MessageConstant::Error::OUT_OF_RANGE = "Input is out of range. Please try again. (1-8)";
