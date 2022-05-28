#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;


void print_map(map<char,double>& mp){
    cout << "printing map" << endl;
    for(auto &p:mp){
        cout<<p.first<<" : "<<p.second<<endl;
    }
};

void print_mmap(multimap<const double, char, std::greater<const double>>& mp) {
    for (auto & p : mp) {
        cout << p.first << " : " << p.second << endl;
    }
};

auto flip_map(multimap<const double, char, std::greater<const double>>mmp)
{
    map<char, double> mp{};
    for (auto&& p : mmp)
    {
        mp.insert(make_pair(p.second, p.first));
    }
    return mp;
}

char* replace2(char* cypher,int len) {
    for (int i = 0; i < len; i++) {
        switch (cypher[i])
        {
        case 'a':
            cypher[i] = 'v';
            break;
        case 'b':
            cypher[i] = 'w';
            break;
        case 'c':
            cypher[i] = 'g';
            break;
        case 'd':
            cypher[i] = 'h';
            break;
        case 'e':
            cypher[i] = 'e';
            break;
        case 'f':
            cypher[i] = 'v';
            break;
        case 'g':
            cypher[i] = 'b';
            break;
        case 'h':
            cypher[i] = 'u';
            break;
        case 'i':
            cypher[i] = 'x';
            break;
        case 'j':
            cypher[i] = 's';
            break;
        case 'k':
            cypher[i] = 't';
            break;
        case 'l':
            cypher[i] = 'j';
            break;
        case 'm':
            cypher[i] = 'p';
            break;
        case 'n':
            cypher[i] = 'f';
            break;
        case 'o':
            cypher[i] = 'z';
            break;
        case 'p':
            cypher[i] = 'i';
            break;
        case 'q':
            cypher[i] = 'a';
            break;
        case 'r':
            cypher[i] = 'c';
            break;
        case 's':
            cypher[i] = 'o';
            break;
        case 't':
            cypher[i] = 'y';
            break;
        case 'u':
            cypher[i] = 'q';
            break;
        case 'v':
            cypher[i] = 'k';
            break;
        case 'w':
            cypher[i] = 'l';
            break;
        case 'x':
            cypher[i] = 'm';
            break;
        case 'y':
            cypher[i] = 'n';
            break;
        case 'z':
            cypher[i] = 'd';
            break;
        default:
            // cout << "i " << i << " " << cypher[i] << " ";
            break;
        }
    }

    return cypher;
}

char* replace1(char* cypher,int len) {
    for (int i = 0; i < len; i++) {
        switch (cypher[i])
        {
        case 'a':
            cypher[i] = 'g';
            break;
        case 'b':
            cypher[i] = 'a';
            break;
        case 'c':
            cypher[i] = 'r';
            break;
        case 'd':
            cypher[i] = 'w';
            break;
        case 'e':
            cypher[i] = 'y';
            break;
        case 'f':
            cypher[i] = 'v';
            break;
        case 'g':
            cypher[i] = 'l';
            break;
        case 'h':
            cypher[i] = 'h';
            break;
        case 'i':
            cypher[i] = 'c';
            break;
        case 'j':
            cypher[i] = 'n';
            break;
        case 'k':
            cypher[i] = 't';
            break;
        case 'l':
            cypher[i] = 'b';
            break;
        case 'm':
            cypher[i] = 'e';
            break;
        case 'n':
            cypher[i] = 'n';
            break;
        case 'o':
            cypher[i] = 'o';
            break;
        case 'p':
            cypher[i] = 'f';
            break;
        case 'q':
            cypher[i] = 'z';
            break;
        case 'r':
            cypher[i] = 'k';
            break;
        case 's':
            cypher[i] = 's';
            break;
        case 't':
            cypher[i] = 'p';
            break;
        case 'u':
            cypher[i] = 'u';
            break;
        case 'v':
            cypher[i] = 'i';
            break;
        case 'w':
            cypher[i] = 'd';
            break;
        case 'x':
            cypher[i] = 'm';
            break;
        case 'y':
            cypher[i] = 's';
            break;
        case 'z':
            cypher[i] = 'o';
            break;
        default:
            // cout << "i " << i << " " << cypher[i] << " ";
            break;
        }
    }

    return cypher;
}

void decypher1(string cypher){
    map<int, int> dict;
    for (int i = 0; i < cypher.length(); i++)
    {
        dict[cypher[i]]++;
    }
    int sum = 0;
    for (int i = 97; i < 123; i++)
    {
        sum += dict[i];
    }
    map <char,double> freq;
    multimap<const double, char,std::greater<const double>> sorted_freq;

    for (int i = 97; i < 123; i++)
    {
        const double percent = (double)dict[i] / (double)sum * 100.0;
        stringstream tmp{};
        tmp << setprecision(2) << fixed << percent;
        double new_val = stod(tmp.str());
        char tch=i;
        sorted_freq.insert(make_pair(new_val, tch));
    }
    
    printf("Frequency distribution of cypher 1: (In %)\n");
    print_mmap(sorted_freq);
    cout << "\nPlaintext: \n";
    int len = cypher.length();
    stringstream  plaintext(replace1(cypher.data(), len));
    cout << plaintext.str() << "\n\n";

}

void decypher2(string cypher){
    map<int, int> dict;
    for (int i = 0; i < cypher.length(); i++)
    {
        dict[cypher[i]]++;
    }
    int sum = 0;
    for (int i = 97; i < 123; i++)
    {
        sum += dict[i];
    }
    map <char,double> freq;
    multimap<const double, char,std::greater<const double>> sorted_freq;

    for (int i = 97; i < 123; i++)
    {
        const double percent = (double)dict[i] / (double)sum * 100.0;
        stringstream tmp{};
        tmp << setprecision(2) << fixed << percent;
        double new_val = stod(tmp.str());
        char tch=i;
        sorted_freq.insert(make_pair(new_val, tch));
    }
    
    printf("Frequency distribution of cypher 2: (In %)\n");
    print_mmap(sorted_freq);
    cout << "\nPlaintext: \n";
    int len = cypher.length();
    stringstream  plaintext(replace2(cypher.data(), len));
    cout << plaintext.str() << endl;

}

int main()
{

    string cypher1 = "dzzw pczay zp bgbyrb bcm yuctcvyvjage ykbcjam. vj dvjkmc, khme lmizxm \
pczqmj. kdz-khvcwy zp khmvc lzwe dbkmc kucjy vjkz vim. vp ezu lmjk zjm zp khmvc gmay, \
vk dzugw lcmbr. vjyvwm khmym pczqmj pczay, khmvc hmbcky ykzt lmbkvja, khmvc lgzzw jz \
gzjamc pgzdy bjw khmvc aguizym gmfmgy yre czirmk. khm icbqvmyk khvja zp bgg xbe lm \
khbk vj khvy pczqmj ykbkm, khme ibj dvkhykbjw kmxtmcbkucmy by gzd by qmcz \
wmacmmy pbhcmjhmvk pzc by gzja by ymfmj xzjkhy, bjw khmj, dhmj ytcvja bccvfmy, khbd \
zuk bjw hzt bdbe.";

    string cypher2 = "bdey tsh wssv qk kde jeqj qyz sreqyj sy kde xqm tsh xpcdk kdpyv kdqk kdet lhjk \
nwsb pyks eqrd skdef. pk jeexj wpve kdefe’j sywt sye gpc sreqy, qyz mesmwe lhjk cqae \
zpnnefeyk yqxej ks pkj mqfkj. beww, tsh’ww ge qxqoez qk dsb apapz kde gsfzefj gekbeey \
kdex qfe! kde gsfzef gekbeey kde mqrpnpr qyz qkwqykpr sreqyj pj wpve q wpye gekbeey kbs \
bsfwzj. pk wssvj qj pn kde kbs sreqyj xeek qk qy pyapjpgwe bqww bdprd zsej ysk wek kdex \
nwsb pyks eqrd skdef qyz xpi kdepf bqkefj. \
bdt sy eqfkd zsej pk dqmmey? \
be vysb nsf jhfe kdefe pj ys pyapjpgwe bqww pyjpze, qyz bqkef pj bqkef. bdqk rshwz \
pykefnefe bpkd pkj xpipyc? \
kde kdpyc pj kdqk bqkef rqy ge zpnnefeyk kss. kde qkwqykpr qyz kde mqrpnpr sreqyj dqae \
zpnnefeyk zeyjpkt qyz rdexprqw xqve-hm, kde weaew sn jqwpypkt qyz skdef uhqwpkpej. \
sye rqy jee gt kdepf rswsf kdqk kdet qfe nqf nfsx gepyc kde jqxe. kde gsfzefj gekbeey kbs \
gszpej sn bqkef bpkd zpnnefeyk mdtjprqw qyz gpswscprqw rdqfqrkefpjkprj qfe vysby qj \
sreqy rwpyej. dqwsrwpyej – gsfzefj gekbeey bqkefj bpkd zpnnefeyk jqwpypkt – qfe kde xsjk \
jmerkqrhwqf, qyz kdpj pj bdqk be jee bdey kde qkwqykpr qyz kde mqrpnpr sreqyj xeek. \
kde nqxshj eimwsfef lqruhej rshjkeqh nshyz kdpj bdey de bqj zeem zpapyc py kde jkfqpk sn \
cpgfqwkqf. kde wqtefj sn bqkef bpkd zpnnefeyk jqwpypkt wssvez wpve kdet befe zpapzez \
bpkd q kfqyjmqfeyk npwx, qyz eqrd wqtef dqz pkj sby nwsfq qyz nqhyq. dqwsrwpyej \
qmmeqf bdey bqkef py sye sreqy sf jeq pj qk weqjk npae kpxej jqwkpef kdqy py kde skdef. \
tsh rqy rfeqke q dqwsrwpye qk dsxe pn tsh mshf jsxe jeqbqkef sf rswsfez jqwkt bqkef py q \
cwqjj qyz kdey qzz jsxe nfejd bqkef sy ksm sn pk. kde sywt zpnnefeyre pj kdqk tshf \
dqwsrwpye bpww ge dsfposykqw, qyz sreqy dqwsrwpyej qfe aefkprqw. pn tsh fexexgef q \
rshmwe sn gqjpr kdpycj nfsx mdtjprj tsh xpcdk qfche kdqk q zeyjef wpuhpz jdshwz \
npyqwwt eyz hm wsbef qyz wejj zeyje dpcdef. pn kdqk befe kfhe kde gsfzef gekbeey kde kbs \
sreqyj bshwz wssv ysk wpve q aefkprqw wpye ghk qj q dsfposykqw sye, qyz kde zpnnefeyre \
gekbeey kdepf jqwpypkt bshwz gersxe wejj sgapshj kde rwsjef kdet csk ks eqrd skdef." ;

    decypher1(cypher1);
    decypher2(cypher2);
    return 0;
}