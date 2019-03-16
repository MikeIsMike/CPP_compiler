#include "ast.hpp"
#include "ast_python.cpp"

#include <fstream>

int main(int argc, char *argv[])
{
    if(argc < 5){
        fprintf(stderr, "usage : compiler sourceCode\n");
        exit(1);
    }

    // std::ifstream src(argv[2]);

    FILE *src;
    src=fopen(argv[2], "r");
    if(!src){
        fprintf(stderr, "Couldn't open '%s'\n", argv[2]);
        exit(1);
    }

    const Translation_unit *ast=parseAST(src);

    if(std::string(argv[1])=="--translate"){
        std::ofstream outfile (argv[4]);

        print_python(outfile);
        //outfile << "my text here!" << std::endl;
        //pass outfile as an argument to translate function and print python code into it like above
        // run translate function with tree and outfile
        outfile<<"if __name__ == \"__main__\":\n\timport sys\n\tret=main()\n\tsys.exit(ret)"<<std::endl;
        outfile.close();
    }
    else if(std::string(argv[1])=="-S"){

        std::ofstream outfile (argv[4]);

        //outfile << "my text here!" << std::endl;
        //pass outfile as an argument to compile function and print MIPS code into it like above
        // Compile(tree, outfile)// run compiler function with tree

        outfile.close();
    }


    return 0;
}
