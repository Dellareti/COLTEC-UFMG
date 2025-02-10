package MainClasses;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

public class AllData {
    public ArrayList <Cliente> clientes = new ArrayList <>();
    public ArrayList <Aeroporto> aeroportos = new ArrayList <>();
    public ArrayList <Aviao> avioes = new ArrayList <>();
    public ArrayList <Voo> voos = new ArrayList <>();
    final String [] arquivos = {"clientes.txt","voos.txt","aeroportos.txt","avioes.txt"};
    
    public AllData(){
        //verifica a existencia de todos os arquivos e carrega os dados
        System.out.println("------------------------------------------------\nBuscando dados...");
        if(this.verificaExistenciaArquivo(arquivos[0])){
            System.out.println("Encontrei: " + arquivos[0]);
            this.carregarDadosClientes();
        }
        else{
            System.out.println("Não encontrei: " + arquivos[0]);
        }
        if(this.verificaExistenciaArquivo(arquivos[1])){
            System.out.println("Encontrei: " + arquivos[1]);
            this.carregarDadosVoos();
        }
        else{
            System.out.println("Não encontrei: " + arquivos[1]);
        }
        if(this.verificaExistenciaArquivo(arquivos[2])){
            System.out.println("Encontrei: " + arquivos[2]);
            this.carregarDadosAeroportos();
        }
        else{
            System.out.println("Não encontrei: " + arquivos[2]);
        }
        if(this.verificaExistenciaArquivo(arquivos[3])){
            System.out.println("Encontrei: " + arquivos[3]);
            this.carregarDadosAvioes();
        }
        else{
            System.out.println("Não encontrei: " + arquivos[3]);
        }
        System.out.println("------------------------------------------------");
    }
    public final boolean verificaExistenciaArquivo(String nome){
        File arq = new File(nome);
        return (arq.exists() && !arq.isDirectory());
    }

    //------------------------------------------------------
    //LEITURA DE ARQUIVOS
    public void carregarDadosClientes(){
        try {
            try (FileReader arq = new FileReader("clientes.txt")) {

                BufferedReader lerArq = new BufferedReader(arq);
                String Linha = lerArq.readLine();
                int cont = 2;
                Cliente cliente = new Cliente();
                cliente.setNome(Linha);
                while (Linha != null) {
                    Linha = lerArq.readLine();
                    if(Linha!=null){
                        if(Linha.equals("@")){
                            lerArq = this.carregaReservasViagens(this.clientes.size()-1,lerArq);
                            //System.out.println("ReservasEncontradas");
                        }
                    }
                    switch (cont) {
                        case 1:
                            cliente.setNome(Linha);
                            break;
                        case 2:
                            cliente.setCPF(Linha);
                            break;
                        case 3:
                            cliente.setTelefone(Linha);
                            break;
                        case 4:
                            cliente.getEndereco().setRua(Linha);
                            break;
                        case 5:
                            cliente.getEndereco().setNum(Linha);
                            break;
                        case 6:
                            cliente.getEndereco().setBairro(Linha);
                            break;
                        case 7:
                            cliente.getEndereco().setCidade(Linha);
                            this.clientes.add(cliente);
                            cliente = new Cliente();
                            cont = 0;
                            break;
                        default:
                            break;
                    }
                    cont++;
                }      
            }
        }
        catch (IOException e) {
            System.err.printf("Erro na abertura do arquivo: %s.\n",
            e.getMessage());
        }
    }

    public BufferedReader carregaReservasViagens(int pos,BufferedReader lerArq){
        String Linha = "vazio";
        while(!(Linha.equals("@"))){
            try {
                Linha = lerArq.readLine();
                //System.out.println(Linha);
                if(Linha.equals("#")){
                    ReservaDeViagem res = new ReservaDeViagem();
                    //System.out.println("NOVA RESERVA DE VIAGEM");
                    do{
                        Linha = lerArq.readLine();
                        
                        Voo novo = this.encontraVoo(Linha);
                        //System.out.println("NOVA RESERVA DE VOO");
                        if(novo!=null)
                            res.getReservasDeVoos().add(new ReservaDeVoo(novo));
                    }while(!(Linha.equals("#")));
                    this.clientes.get(pos).getReservasViagens().add(res);
                    //System.out.println(Linha);
                }  
            } catch (IOException ex) {
                Logger.getLogger(AllData.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        return lerArq;
    }
        
    public void carregarDadosAeroportos(){
        try (FileReader arq = new FileReader("aeroportos.txt")) {
            BufferedReader lerArq = new BufferedReader(arq);
            String Linha = lerArq.readLine();
            int cont = 1;
            Aeroporto aeroporto = new Aeroporto();
            aeroporto.setNome(Linha);

            while (Linha != null) {
                Linha = lerArq.readLine();
                //System.out.println(Linha);
                cont++;
                switch (cont) {
                    case 1:
                        aeroporto.setNome(Linha);
                        break;
                    case 2:
                        aeroporto.setCodigo(Linha);
                        break;
                    case 3:
                        aeroporto.setCidade(Linha);
                        this.aeroportos.add(aeroporto);
                        aeroporto = new Aeroporto();
                        cont = 0;
                        break;
                    default:
                        break;
                }
            }     
        } catch (IOException ex) {
            Logger.getLogger(AllData.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public void carregarDadosVoos(){
        try (FileReader arq = new FileReader("voos.txt")){
            BufferedReader lerArq = new BufferedReader(arq);
            String Linha = null;
            try {
                Linha = lerArq.readLine();
            } catch (IOException ex) {
                Logger.getLogger(AllData.class.getName()).log(Level.SEVERE, null, ex);
            }
            int cont = 1;
            Voo v = new Voo();
            v.setDataDePartida(Linha);
            while (Linha != null) {
                Linha = lerArq.readLine();
                //System.out.println(Linha); 
                cont++;
                switch (cont) {
                    case 1:
                        v.setDataDePartida(Linha);
                        break;
                    case 2:
                        v.setSNumVagas(Linha);
                        break;
                    case 3:
                        v.getDescVoo().setHorarioDePartida(Linha);
                        break;
                    case 4:
                        v.getDescVoo().setHorarioDeChegada(Linha);
                        break;
                    case 5:
                        v.getDescVoo().setNumeroDoVoo(Linha);
                        break;
                    case 6:
                        v.getDescVoo().setAeroPartida(Linha);
                        break;
                    case 7:
                        v.getDescVoo().setAeroChegada(Linha);
                        break;
                    case 8:
                        v.getAv().setNumModelo(Linha);
                        break;
                    case 9:
                        v.getAv().setNomeDoFabricante(Linha);
                        break;
                    case 10:
                        v.getAv().setNumAssentos(Linha);
                        this.voos.add(v);
                        v = new Voo();
                        cont = 0;
                        break;
                    default:
                        break;
                }
            }
        } catch (IOException ex) {
            Logger.getLogger(AllData.class.getName()).log(Level.SEVERE, null, ex);
        }               
    }
    
    public void carregarDadosAvioes(){
         try (FileReader arq = new FileReader("avioes.txt")){
            BufferedReader lerArq = new BufferedReader(arq);
            String Linha = null;
            try {
                Linha = lerArq.readLine();
            } catch (IOException ex) {
                Logger.getLogger(AllData.class.getName()).log(Level.SEVERE, null, ex);
            }
            int cont = 2;
            Aviao av = new Aviao();
            av.setNomeDoFabricante(Linha);
            while (Linha != null) {
                Linha = lerArq.readLine();
                //System.out.println(Linha);                     
                switch (cont) {
                    case 1:
                        av.setNomeDoFabricante(Linha);
                        break;
                    case 2:
                        av.setNumModelo(Linha);
                        break;
                    case 3:
                        av.setNumAssentos(Linha);
                        this.avioes.add(av);
                        av = new Aviao();
                        cont = 0;
                        break;
                    default:
                        break;
                }
                cont++;
            }
        } catch (IOException ex) {
            Logger.getLogger(AllData.class.getName()).log(Level.SEVERE, null, ex);
        }       
    }

    //------------------------------------------------------
    //ESCRITA EM ARQUIVOS
    public void escreverDadosClientes(){
        FileWriter arq=null;
        try{
            arq = new FileWriter("clientes.txt");
            PrintWriter gravarArq = new PrintWriter(arq);
            for (Cliente cliente : clientes) {
                gravarArq.printf(cliente.getNome() + "\n");
                gravarArq.printf(cliente.getCPF() + "\n");
                gravarArq.printf(cliente.getTelefone() + "\n");
                gravarArq.printf(cliente.getEndereco().getRua() + "\n");
                gravarArq.printf(cliente.getEndereco().getNum() + "\n");
                gravarArq.printf(cliente.getEndereco().getBairro() + "\n");
                gravarArq.printf(cliente.getEndereco().getCidade() + "\n@\n");
                for(ReservaDeViagem res: cliente.getReservasViagens()){
                    gravarArq.printf("#\n");
                        for(ReservaDeVoo rV : res.getReservasDeVoos()){
                            gravarArq.printf(rV.getVoo().getDescVoo().getNumeroDoVoo()+"\n");
                        }
                    gravarArq.printf("#\n");
                }
                gravarArq.printf("@\n");
            }
            arq.close();
        }
        catch(FileNotFoundException e){}
        catch(IOException e){}
    }
    
    public void escreverDadosVoos(){
        FileWriter arq=null;
        try{
            arq = new FileWriter("voos.txt");
            PrintWriter gravarArq = new PrintWriter(arq);
            for (Voo voo : voos) {
                gravarArq.printf(voo.getDataDePartida()+"\n");
                gravarArq.printf(voo.getSNumVagas()+"\n");
                gravarArq.printf(voo.getDescVoo().getHorarioDePartida()+"\n");
                gravarArq.printf(voo.getDescVoo().getHorarioDeChegada()+"\n");
                gravarArq.printf(voo.getDescVoo().getNumeroDoVoo()+"\n");
                gravarArq.printf(voo.getDescVoo().getAeroPartida()+"\n");
                gravarArq.printf(voo.getDescVoo().getAeroChegada()+"\n");
                gravarArq.printf(voo.getAv().getNumModelo()+"\n");
                gravarArq.printf(voo.getAv().getNomeDoFabricante()+"\n");
                gravarArq.printf(voo.getAv().getNumAssentos()+"\n");
            }
            arq.close();
        }
        catch(FileNotFoundException e){}
        catch(IOException e){}
    }
    
    public void escreverDadosAeroportos(){
        FileWriter arq=null;
        try{
            arq = new FileWriter("aeroportos.txt");
            PrintWriter gravarArq = new PrintWriter(arq);
            for (Aeroporto aero : aeroportos) {
                gravarArq.printf(aero.getNome()+"\n");
                gravarArq.printf(aero.getCodigo()+"\n");
                gravarArq.printf(aero.getCidade()+"\n");
            }
            arq.close();
        }
        catch(FileNotFoundException e){}
        catch(IOException e){}
    }

    public void escreverDadosAvioes(){
        FileWriter arq=null;
        try{
            arq = new FileWriter("avioes.txt");
            PrintWriter gravarArq = new PrintWriter(arq);
            for (Aviao aviao : avioes) {
                gravarArq.printf(aviao.getNomeDoFabricante()+"\n");
                gravarArq.printf(aviao.getNumModelo()+"\n");
                gravarArq.printf(aviao.getNumAssentos()+"\n");
            }
            arq.close();
        }
        catch(FileNotFoundException e){}
        catch(IOException e){}
    }

    //------------------------------------------------------
     //METODOS CLIENTES
    public void addCliente(Cliente cli){
        this.clientes.add(cli);
    }
    public Cliente buscarCliente(String cpf){
        for(Cliente c : this.clientes){
            if(c.getCPF().equals(cpf))
                return c;
        }
        return null;

    }
    public void removeCliente(int pos){
        this.clientes.remove(pos);
    }

     public Voo buscaVoo(String n){
        for(Voo v : this.voos){
            if(v.getDescVoo().getNumeroDoVoo().equals(n))
                return v;
        }
        return null;
    }


    //METODOS AEROPORTO
    public void addAeroP(Aeroporto aerop){
        this.aeroportos.add(aerop);
    }
    public void removeAeroP(int pos){
        this.aeroportos.remove(pos);
    }
    public Aeroporto buscaAeroP(String codigo){
        for(Aeroporto aero : this.aeroportos){
            if(aero.getCodigo().equals(codigo))
                return aero;
        }
        return null;
    }
    public Aeroporto buscaAeroPNome(String nome){
        for(Aeroporto aero : this.aeroportos){
            if(aero.getNome().equals(nome))
                return aero;
        }
        return null;
    }
 
    //------------------------------------------------------
    //METODOS AVIAO
    public void addAviao(Aviao av){
        this.avioes.add(av);
    }
    public void removeAviao(int pos){
        this.avioes.remove(pos);
    }
    public Aviao buscaAviaoModel(String modelo){
        for(Aviao av : this.avioes){
            if(av.getNumModelo().equals(modelo))
                return av;
        }
        return null;
    }
    //------------------------------------------------------
    //METODOS VOOS
    public Voo encontraVoo(String nVoo){
        for(Voo v : this.voos){
            if(v.getDescVoo().getNumeroDoVoo().equals(nVoo))
                return v;
        }
        return null;
    }
    public void addVoo(Voo voo){
        Random rand = new Random();
        int numeroVoo = rand.nextInt(10000)+1;
        for(Voo v : this.voos){
            if(Integer.parseInt(v.getDescVoo().getNumeroDoVoo())==numeroVoo){
                rand = new Random();
                numeroVoo = rand.nextInt(10000)+1;
            }
        }
        voo.getDescVoo().setNumeroDoVoo(String.valueOf(numeroVoo));
        this.voos.add(voo);
    }
    
    public void removeVoo(int pos){
        this.voos.remove(pos);
    }
    public Voo buscarVoo(String codigo){
        for(Voo vvv : this.voos){
            if(vvv.getDescVoo().getNumeroDoVoo().equals(codigo))
                return vvv;
        }
        return null;
    }
    
    public String buscarVoo2(String ctog, String ctdt){
        for(Voo vvv : this.voos){
            if(ctog.equals((this.buscaAeroPNome(vvv.getDescVoo().getAeroPartida())).getCidade()) 
                    && ctdt.equals((this.buscaAeroPNome(vvv.getDescVoo().getAeroChegada() )).getCidade())) {
                return vvv.getDescVoo().getNumeroDoVoo();
            } 
            else {
                System.out.println("Não Deu");
                return null;
            }
        } return null;
    }
    //------------------------------------------------------
    //GETTERS E SETTERS
    public ArrayList<Cliente> getClientes() {
        return clientes;
    }
    public void setClientes(ArrayList<Cliente> clientes) {
        this.clientes = clientes;
    }
    public ArrayList<Aeroporto> getAeroportos() {
        return aeroportos;
    }
    public void setAeroportos(ArrayList<Aeroporto> aeroportos) {
        this.aeroportos = aeroportos;
    }
    public ArrayList<Aviao> getAvioes() {
        return avioes;
    }
    public void setAvioes(ArrayList<Aviao> avioes) {
        this.avioes = avioes;
    }
    public ArrayList<Voo> getVoos() {
        return voos;
    }
    public void setVoos(ArrayList<Voo> voos) {
        this.voos = voos;
    }
    
 
    public static void main(String[] args) {
        AllData a = new AllData();
        System.out.println(a.clientes.get(0).getReservasViagens().size());
        System.out.println(a.clientes.get(0).getReservasViagens().get(0).getReservasDeVoos().size());
        
    }
}