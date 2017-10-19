#include <fstream>
#include <list>
#include <string>
using namespace std;

class person
{
public:
    person(){};
    ~person(){};
    void no(int n){num = n;}
    void speak(string alpha, bool order)
    {
        if (order)
           word = word + alpha;
        else 
            word = alpha + word;
    }
    int no(){return num;}
    string tell(){return word;}
private:
    int num;
    string word;
};

int main(int argc,char** argv)
{
    fstream fin, fout;
    int start;
    int n;
    bool inorder = true;
    char c;
    string word;
    person now;
    list<person> circle;
    list<person>::iterator it;

    fin.open(argv[1],fstream::in);
    fout.open(argv[2],fstream::out);
    
    fin >> start;
    while(fin>>n) 
    {
        if (n<0) 
            break;
        now.no(n);
        circle.push_back(now);
        if (now.no()==start)
            it = --circle.end();
    }

    while(circle.size()!=1) 
    {
        fin >> word;
        for (unsigned int i=0;i<word.size()-1;++i)
        {
            string ch;
            ch.push_back(word[i]); 
            it->speak(ch,inorder);
            if(inorder) 
            {
                ++it;
                if (it==circle.end())
                    it = circle.begin();
            }
            else 
            {
                --it;
                if (it==--circle.begin())
                    it = --circle.end();
            }
        }
        
        c = *(--word.end());
        word.clear();
        word.push_back(c);
        it->speak(word,inorder);
        
        fout << it->no() << " " << it->tell() << endl;
        it = circle.erase(it);
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            inorder = inorder;
        else 
            inorder = !inorder;
        
        if (inorder)
        {
            if (it==circle.end())
                it = circle.begin();
        }
        else 
        {
            if (it==circle.begin())
                it = circle.end();
            --it;
            if (circle.size()==1)
                it = circle.begin();
        }
    }

    fout << it->no() << " " << it->tell();

    fin.close();
    fout.close();
    return 0;
}