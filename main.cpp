#include <iostream>
#include <string>
#include <list>

class Amigo {
private:
public:
    Amigo(std::string nome, char sexo, int idade) {
    }

    std::string get_nome() {
	return "";
    }

    std::string get_mensagem() {
        return "";
    }

    char get_sexo() {
        return 'a';
    }

    int get_idade() {
        return 0;
    }

    void set_mensagem(std::string mensagem) {
    }
};

class Rede {
public:

    int pesquisar_amigo(std::string nome) {
        return -1;
    }

    Amigo* obter_amigo(std::string nome) {
        return nullptr;
    }

    void adicionar_amigo(Amigo* amigo) {
        
    }

    void adicionar_amigo(std::string nome, char sexo, int idade) {
        
    }

    void remover_amigo (std::string nome) {
    
    }

    void enviar_mensagem(std::string nome, std::string mensagem) {
    }
};

void CHECK(bool condition) {
    if (!condition) {
        std::cout << "F";
    } else {
        std::cout << ".";
    }
}

void teste_case_1() {
    // teste amigo class
    Amigo *amigo = new Amigo("teste um", 'M', 23);
    CHECK(amigo->get_nome() == "teste um");
    CHECK(amigo->get_idade() == 23);
    CHECK(amigo->get_sexo() == 'M');
    CHECK(amigo->get_mensagem() == "");
    amigo->set_mensagem("mensagem de teste");
    CHECK(amigo->get_mensagem() == "mensagem de teste");
}

void teste_case_2() {
    Rede *rede = new Rede();
    rede->adicionar_amigo(new Amigo("teste um", 'M', 23));
    rede->adicionar_amigo("teste dois", 'F', 22);
    CHECK(rede->pesquisar_amigo("teste um") == 0);
    CHECK(rede->pesquisar_amigo("teste dois") == 1);
    CHECK(rede->pesquisar_amigo("teste tres") == -1);
}

void teste_case_3() {
    Rede *rede = new Rede();
    rede->adicionar_amigo(new Amigo("teste um", 'M', 23));
    rede->adicionar_amigo("teste dois", 'F', 22);
    CHECK(rede->obter_amigo("teste um")->get_idade() == 23);
    CHECK(rede->obter_amigo("teste dois")->get_idade() == 22);
    CHECK(rede->obter_amigo("teste tres") == nullptr);
}

void teste_case_4() {
    Rede *rede = new Rede();
    rede->adicionar_amigo(new Amigo("teste um", 'M', 23));
    rede->adicionar_amigo("teste dois", 'F', 22);
    rede->adicionar_amigo("teste tres", 'F', 22);
    CHECK(rede->pesquisar_amigo("teste um") == 0);
    CHECK(rede->pesquisar_amigo("teste dois") == 1);
    CHECK(rede->pesquisar_amigo("teste tres") == 2);

    rede->remover_amigo("teste dois");

    CHECK(rede->pesquisar_amigo("teste um") == 0);
    CHECK(rede->pesquisar_amigo("teste dois") == -1);
    CHECK(rede->pesquisar_amigo("teste tres") == 1);
}

void teste_case_5() {
    Rede *rede = new Rede();
    rede->adicionar_amigo(new Amigo("teste um", 'M', 23));
    rede->adicionar_amigo("teste dois", 'F', 22);
    rede->enviar_mensagem("teste um", "mensagem um");
    CHECK(rede->obter_amigo("teste um")->get_mensagem() == "mensagem um");
    CHECK(rede->obter_amigo("teste dois")->get_mensagem() == "");
    rede->enviar_mensagem("teste dois", "mensagem dois");
    CHECK(rede->obter_amigo("teste um")->get_mensagem() == "mensagem um");
    CHECK(rede->obter_amigo("teste dois")->get_mensagem() == "mensagem dois");
}

int main() {
    teste_case_1();
    teste_case_2();
    teste_case_3();
    teste_case_4();
    teste_case_5();
    return 0;
}
