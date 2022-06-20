

#ifndef ASTENENKO_SUBMANAGERCOMMAND_H
#define ASTENENKO_SUBMANAGERCOMMAND_H

#include "../../controller/IController.h"
#include <typeinfo>
#include "../CommandManager.h"
#include "PrintCommand.h"
#include "ExitCommand.h"
#include "CreateCommand.h"
#include "DeleteCommand.h"

template<typename Controller>
class SubManagerCommand : public ICommand{
    IController<Controller> *controller;
    CommandManager *manager{};
    std::vector<ICommand*> commands;

    void init(){
        this->controller = TypeBase::get<Controller>();
        manager = new CommandManager();

        manager->addCommand(new PrintCommand(this->controller));
        manager->addCommand(new CreateCommand(this->controller));
        manager->addCommand(new DeleteCommand(this->controller));
        for (const auto &item: this->commands){
            manager->addCommand(item);
        }

        manager->addCommand(new ExitCommand());
    }

public:

    SubManagerCommand(){
        init();
    }
    template<class ... Commands>
    explicit SubManagerCommand(Commands&& ... commands) : commands{std::forward<Commands>(commands)...}{
        init();
    }


    void handle(AppContext *context, std::vector<std::string> args) override {
        std::string input;
        while (context->isRunning()){
            std::cout<<*manager;
            std::cin>>input;
            try {
                manager->handle(context, input);
            }catch (std::runtime_error const& error){
                std::cout<<error.what()<<"\n";
            }
        }
        context->run();
    }

    std::string getName() override {
        return "manage_" + this->controller->name();
    }

    std::string getAliases() override {
        return "manage " + this->controller->name();
    }

};


#endif //ASTENENKO_SUBMANAGERCOMMAND_H
