package GUIClasses;

import GUIClasses.aeroporto.AddAeroP;
import GUIClasses.aeroporto.BuscarAeroP;
import GUIClasses.aeroporto.EditarAeroP;
import GUIClasses.aeroporto.RemAeroP;
import GUIClasses.aviao.EditarAviao;
import GUIClasses.aviao.RemAviao;
import GUIClasses.aviao.AddAviao;
import GUIClasses.cliente.AdicionarCliente;
import GUIClasses.cliente.AdicionarReservaCliente;
import GUIClasses.voo.AddVoo;
import GUIClasses.voo.BuscarVoo;
import GUIClasses.voo.EditarVoo;
import GUIClasses.voo.RemVoo;
import GUIClasses.voo.BuscarVoo2;
import GUIClasses.cliente.EditarCliente;
import GUIClasses.cliente.RemoverCliente;
import GUIClasses.cliente.BuscarCliente;
import GUIClasses.cliente.IncluirVoo;
import GUIClasses.cliente.RemoverReservaCliente;
import GUIClasses.cliente.RemoverVooViagem;

import MainClasses.AllData;
import java.awt.CardLayout;
import java.awt.Cursor;
import java.awt.FlowLayout;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.ImageIcon;
import java.awt.Image;



public class TelaPrincipal extends javax.swing.JFrame {

    public TelaPrincipal() {
        initComponents();
        
    }

    //-----------------------------------------
    //-----------------------------------------
    AllData dados = new AllData();
    //-----------------------------------------
    //-----------------------------------------
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton4 = new javax.swing.JButton();
        jLabel4 = new javax.swing.JLabel();
        TelaRaiz = new javax.swing.JPanel();
        telaPrincipal = new javax.swing.JPanel();
        telaClientes = new javax.swing.JButton();
        telaVoos = new javax.swing.JButton();
        telaAeroportos = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        AeroportoRaiz = new javax.swing.JPanel();
        removerAeroP = new javax.swing.JButton();
        editarAeroP = new javax.swing.JButton();
        adicionarAeroP = new javax.swing.JButton();
        voltarAR = new javax.swing.JButton();
        buscarAeroP = new javax.swing.JButton();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        VooRaiz = new javax.swing.JPanel();
        editarVoo = new javax.swing.JButton();
        remVoo = new javax.swing.JButton();
        jButton6 = new javax.swing.JButton();
        jButton5 = new javax.swing.JButton();
        voltarVo = new javax.swing.JButton();
        adicionarVoo = new javax.swing.JButton();
        jLabel3 = new javax.swing.JLabel();
        ClienteRaiz = new javax.swing.JPanel();
        reservasCliente = new javax.swing.JButton();
        voltarCli = new javax.swing.JButton();
        addCliente = new javax.swing.JButton();
        buscarCPF = new javax.swing.JButton();
        reservasVoo = new javax.swing.JButton();
        remCliente = new javax.swing.JButton();
        editarCliente = new javax.swing.JButton();
        jLabel5 = new javax.swing.JLabel();
        ReservasVoo = new javax.swing.JPanel();
        voltarCli1 = new javax.swing.JButton();
        addCliente1 = new javax.swing.JButton();
        reservasVoo1 = new javax.swing.JButton();
        remCliente1 = new javax.swing.JButton();
        jLabel7 = new javax.swing.JLabel();
        ReservasViagem = new javax.swing.JPanel();
        voltarCli2 = new javax.swing.JButton();
        addCliente2 = new javax.swing.JButton();
        reservasVoo2 = new javax.swing.JButton();
        remCliente2 = new javax.swing.JButton();
        jLabel8 = new javax.swing.JLabel();

        jButton4.setText("jButton4");

        jLabel4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/voostelafundo.jpg"))); // NOI18N
        jLabel4.setText("jLabel4");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setBackground(new java.awt.Color(255, 255, 255));
        setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        getContentPane().setLayout(new javax.swing.BoxLayout(getContentPane(), javax.swing.BoxLayout.LINE_AXIS));

        TelaRaiz.setLayout(new java.awt.CardLayout());

        telaPrincipal.setBackground(new java.awt.Color(255, 255, 255));
        telaPrincipal.setToolTipText("");
        telaPrincipal.setMaximumSize(new java.awt.Dimension(800, 800));
        telaPrincipal.setMinimumSize(new java.awt.Dimension(800, 800));
        telaPrincipal.setName(""); // NOI18N
        telaPrincipal.setOpaque(false);
        telaPrincipal.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        telaClientes.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/antesCLIE.jpg"))); // NOI18N
        telaClientes.setText("Clientes");
        telaClientes.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                telaClientesMouseClicked(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                telaClientesMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                telaClientesMouseExited(evt);
            }
        });
        telaClientes.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                telaClientesActionPerformed(evt);
            }
        });
        telaPrincipal.add(telaClientes, new org.netbeans.lib.awtextra.AbsoluteConstraints(50, 100, 143, 325));

        telaVoos.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/antesVOO.jpg"))); // NOI18N
        telaVoos.setText("Voos");
        telaVoos.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                telaVoosMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                telaVoosMouseExited(evt);
            }
        });
        telaVoos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                telaVoosActionPerformed(evt);
            }
        });
        telaPrincipal.add(telaVoos, new org.netbeans.lib.awtextra.AbsoluteConstraints(270, 100, 145, 324));

        telaAeroportos.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/antesAE.jpg"))); // NOI18N
        telaAeroportos.setText("Aeroportos");
        telaAeroportos.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                telaAeroportosMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                telaAeroportosMouseExited(evt);
            }
        });
        telaAeroportos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                telaAeroportosActionPerformed(evt);
            }
        });
        telaPrincipal.add(telaAeroportos, new org.netbeans.lib.awtextra.AbsoluteConstraints(480, 100, 145, 324));

        jLabel1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/titulo.png"))); // NOI18N
        telaPrincipal.add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, -80, -1, 290));

        jLabel6.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/principal.jpg"))); // NOI18N
        jLabel6.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        jLabel6.setMaximumSize(new java.awt.Dimension(800, 720));
        jLabel6.setMinimumSize(new java.awt.Dimension(800, 720));
        jLabel6.setPreferredSize(new java.awt.Dimension(800, 720));
        telaPrincipal.add(jLabel6, new org.netbeans.lib.awtextra.AbsoluteConstraints(-30, -150, 830, 950));

        TelaRaiz.add(telaPrincipal, "telaPrincipal");

        AeroportoRaiz.setLayout(null);

        removerAeroP.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/baseremoveraero.png"))); // NOI18N
        removerAeroP.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                removerAeroPMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                removerAeroPMouseExited(evt);
            }
        });
        removerAeroP.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                removerAeroPActionPerformed(evt);
            }
        });
        AeroportoRaiz.add(removerAeroP);
        removerAeroP.setBounds(650, 180, 90, 90);

        editarAeroP.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/baseaeroedita.png"))); // NOI18N
        editarAeroP.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                editarAeroPMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                editarAeroPMouseExited(evt);
            }
        });
        editarAeroP.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                editarAeroPActionPerformed(evt);
            }
        });
        AeroportoRaiz.add(editarAeroP);
        editarAeroP.setBounds(540, 180, 90, 90);

        adicionarAeroP.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/novoaeroporto.jpg"))); // NOI18N
        adicionarAeroP.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                adicionarAeroPMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                adicionarAeroPMouseExited(evt);
            }
        });
        adicionarAeroP.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                adicionarAeroPActionPerformed(evt);
            }
        });
        AeroportoRaiz.add(adicionarAeroP);
        adicionarAeroP.setBounds(540, 280, 200, 120);

        voltarAR.setBackground(new java.awt.Color(0, 0, 0));
        voltarAR.setText("Voltar");
        voltarAR.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                voltarARActionPerformed(evt);
            }
        });
        AeroportoRaiz.add(voltarAR);
        voltarAR.setBounds(40, 30, 100, 30);

        buscarAeroP.setBackground(new java.awt.Color(252, 237, 120));
        buscarAeroP.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/procura1.png"))); // NOI18N
        buscarAeroP.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                buscarAeroPMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                buscarAeroPMouseExited(evt);
            }
        });
        buscarAeroP.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buscarAeroPActionPerformed(evt);
            }
        });
        AeroportoRaiz.add(buscarAeroP);
        buscarAeroP.setBounds(550, 100, 180, 71);

        jButton1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/editaraviao.jpg"))); // NOI18N
        jButton1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                jButton1MouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                jButton1MouseExited(evt);
            }
        });
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        AeroportoRaiz.add(jButton1);
        jButton1.setBounds(200, 100, 180, 300);

        jButton2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/removeaviao_1.png"))); // NOI18N
        jButton2.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                jButton2MouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                jButton2MouseExited(evt);
            }
        });
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });
        AeroportoRaiz.add(jButton2);
        jButton2.setBounds(390, 100, 130, 130);

        jButton3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/baseaviaoedita.png"))); // NOI18N
        jButton3.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                jButton3MouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                jButton3MouseExited(evt);
            }
        });
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });
        AeroportoRaiz.add(jButton3);
        jButton3.setBounds(390, 240, 130, 160);

        jLabel2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/telafundoAERO.jpg"))); // NOI18N
        jLabel2.setText("jLabel2");
        AeroportoRaiz.add(jLabel2);
        jLabel2.setBounds(0, 0, 970, 510);

        TelaRaiz.add(AeroportoRaiz, "telaAeroporto");

        VooRaiz.setLayout(null);

        editarVoo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/draw.png"))); // NOI18N
        editarVoo.setContentAreaFilled(false);
        editarVoo.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                editarVooMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                editarVooMouseExited(evt);
            }
        });
        editarVoo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                editarVooActionPerformed(evt);
            }
        });
        VooRaiz.add(editarVoo);
        editarVoo.setBounds(520, 290, 100, 80);

        remVoo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/1234.png"))); // NOI18N
        remVoo.setContentAreaFilled(false);
        remVoo.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                remVooMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                remVooMouseExited(evt);
            }
        });
        remVoo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                remVooActionPerformed(evt);
            }
        });
        VooRaiz.add(remVoo);
        remVoo.setBounds(520, 210, 90, 90);

        jButton6.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/search.png"))); // NOI18N
        jButton6.setContentAreaFilled(false);
        jButton6.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                jButton6MouseEntered(evt);
            }
        });
        jButton6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton6ActionPerformed(evt);
            }
        });
        VooRaiz.add(jButton6);
        jButton6.setBounds(520, 360, 100, 90);

        jButton5.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/search.png"))); // NOI18N
        jButton5.setContentAreaFilled(false);
        jButton5.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                jButton5MouseEntered(evt);
            }
        });
        jButton5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton5ActionPerformed(evt);
            }
        });
        VooRaiz.add(jButton5);
        jButton5.setBounds(510, 130, 100, 90);

        voltarVo.setBackground(new java.awt.Color(0, 0, 0));
        voltarVo.setText("Voltar");
        voltarVo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                voltarVoActionPerformed(evt);
            }
        });
        VooRaiz.add(voltarVo);
        voltarVo.setBounds(40, 30, 100, 30);

        adicionarVoo.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/adicionarvoo.jpg"))); // NOI18N
        adicionarVoo.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                adicionarVooMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                adicionarVooMouseExited(evt);
            }
        });
        adicionarVoo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                adicionarVooActionPerformed(evt);
            }
        });
        VooRaiz.add(adicionarVoo);
        adicionarVoo.setBounds(300, 100, 210, 330);

        jLabel3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/voostelafundo.jpg"))); // NOI18N
        jLabel3.setText("jLabel2");
        VooRaiz.add(jLabel3);
        jLabel3.setBounds(0, 0, 970, 510);

        TelaRaiz.add(VooRaiz, "telaVoos");

        ClienteRaiz.setLayout(null);

        reservasCliente.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/reservacliente.png"))); // NOI18N
        reservasCliente.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                reservasClienteMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                reservasClienteMouseExited(evt);
            }
        });
        reservasCliente.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                reservasClienteActionPerformed(evt);
            }
        });
        ClienteRaiz.add(reservasCliente);
        reservasCliente.setBounds(570, 150, 150, 230);

        voltarCli.setBackground(new java.awt.Color(0, 0, 0));
        voltarCli.setText("Voltar");
        voltarCli.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                voltarCliActionPerformed(evt);
            }
        });
        ClienteRaiz.add(voltarCli);
        voltarCli.setBounds(40, 30, 100, 30);

        addCliente.setBackground(new java.awt.Color(252, 237, 120));
        addCliente.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/signs.png"))); // NOI18N
        addCliente.setContentAreaFilled(false);
        addCliente.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                addClienteMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                addClienteMouseExited(evt);
            }
        });
        addCliente.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                addClienteActionPerformed(evt);
            }
        });
        ClienteRaiz.add(addCliente);
        addCliente.setBounds(400, 50, 70, 70);

        buscarCPF.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/id-card.png"))); // NOI18N
        buscarCPF.setContentAreaFilled(false);
        buscarCPF.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                buscarCPFMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                buscarCPFMouseExited(evt);
            }
        });
        buscarCPF.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buscarCPFActionPerformed(evt);
            }
        });
        ClienteRaiz.add(buscarCPF);
        buscarCPF.setBounds(630, 50, 80, 70);

        reservasVoo.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                reservasVooMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                reservasVooMouseExited(evt);
            }
        });
        reservasVoo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                reservasVooActionPerformed(evt);
            }
        });
        ClienteRaiz.add(reservasVoo);
        reservasVoo.setBounds(410, 150, 150, 230);

        remCliente.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/close.png"))); // NOI18N
        remCliente.setContentAreaFilled(false);
        remCliente.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                remClienteMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                remClienteMouseExited(evt);
            }
        });
        remCliente.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                remClienteActionPerformed(evt);
            }
        });
        ClienteRaiz.add(remCliente);
        remCliente.setBounds(480, 50, 70, 70);

        editarCliente.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/interface.png"))); // NOI18N
        editarCliente.setContentAreaFilled(false);
        editarCliente.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                editarClienteMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                editarClienteMouseExited(evt);
            }
        });
        editarCliente.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                editarClienteActionPerformed(evt);
            }
        });
        ClienteRaiz.add(editarCliente);
        editarCliente.setBounds(550, 50, 80, 70);

        jLabel5.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/cliente2.jpg"))); // NOI18N
        jLabel5.setText("jLabel2");
        ClienteRaiz.add(jLabel5);
        jLabel5.setBounds(0, 0, 970, 510);

        TelaRaiz.add(ClienteRaiz, "telaCliente");

        ReservasVoo.setLayout(null);

        voltarCli1.setBackground(new java.awt.Color(0, 0, 0));
        voltarCli1.setText("Voltar");
        voltarCli1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                voltarCli1ActionPerformed(evt);
            }
        });
        ReservasVoo.add(voltarCli1);
        voltarCli1.setBounds(40, 30, 100, 30);

        addCliente1.setBackground(new java.awt.Color(252, 237, 120));
        addCliente1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/signs.png"))); // NOI18N
        addCliente1.setContentAreaFilled(false);
        addCliente1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                addCliente1MouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                addCliente1MouseExited(evt);
            }
        });
        addCliente1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                addCliente1ActionPerformed(evt);
            }
        });
        ReservasVoo.add(addCliente1);
        addCliente1.setBounds(490, 230, 70, 70);

        reservasVoo1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                reservasVoo1MouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                reservasVoo1MouseExited(evt);
            }
        });
        reservasVoo1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                reservasVoo1ActionPerformed(evt);
            }
        });
        ReservasVoo.add(reservasVoo1);
        reservasVoo1.setBounds(20, 100, 150, 230);

        remCliente1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/close.png"))); // NOI18N
        remCliente1.setContentAreaFilled(false);
        remCliente1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                remCliente1MouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                remCliente1MouseExited(evt);
            }
        });
        remCliente1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                remCliente1ActionPerformed(evt);
            }
        });
        ReservasVoo.add(remCliente1);
        remCliente1.setBounds(490, 140, 70, 70);

        jLabel7.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/cliente2.jpg"))); // NOI18N
        jLabel7.setText("jLabel2");
        ReservasVoo.add(jLabel7);
        jLabel7.setBounds(0, 0, 970, 510);

        TelaRaiz.add(ReservasVoo, "telaReservaVoo");

        ReservasViagem.setLayout(null);

        voltarCli2.setBackground(new java.awt.Color(0, 0, 0));
        voltarCli2.setText("Voltar");
        voltarCli2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                voltarCli2ActionPerformed(evt);
            }
        });
        ReservasViagem.add(voltarCli2);
        voltarCli2.setBounds(40, 30, 100, 30);

        addCliente2.setBackground(new java.awt.Color(252, 237, 120));
        addCliente2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/signs.png"))); // NOI18N
        addCliente2.setContentAreaFilled(false);
        addCliente2.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                addCliente2MouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                addCliente2MouseExited(evt);
            }
        });
        addCliente2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                addCliente2ActionPerformed(evt);
            }
        });
        ReservasViagem.add(addCliente2);
        addCliente2.setBounds(480, 240, 70, 70);

        reservasVoo2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/reservacliente.png"))); // NOI18N
        reservasVoo2.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                reservasVoo2MouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                reservasVoo2MouseExited(evt);
            }
        });
        reservasVoo2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                reservasVoo2ActionPerformed(evt);
            }
        });
        ReservasViagem.add(reservasVoo2);
        reservasVoo2.setBounds(30, 130, 150, 230);

        remCliente2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/close.png"))); // NOI18N
        remCliente2.setContentAreaFilled(false);
        remCliente2.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                remCliente2MouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                remCliente2MouseExited(evt);
            }
        });
        remCliente2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                remCliente2ActionPerformed(evt);
            }
        });
        ReservasViagem.add(remCliente2);
        remCliente2.setBounds(480, 160, 70, 70);

        jLabel8.setIcon(new javax.swing.ImageIcon(getClass().getResource("/GUIClasses/cliente2.jpg"))); // NOI18N
        jLabel8.setText("jLabel2");
        ReservasViagem.add(jLabel8);
        jLabel8.setBounds(0, 0, 970, 510);

        TelaRaiz.add(ReservasViagem, "telaReservaCliente");

        getContentPane().add(TelaRaiz);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void telaClientesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_telaClientesActionPerformed
        CardLayout cl = (CardLayout)(TelaRaiz.getLayout());
          
        cl.show(TelaRaiz, "telaCliente");
        
        
    }//GEN-LAST:event_telaClientesActionPerformed
   
    private void telaAeroportosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_telaAeroportosActionPerformed
        

        CardLayout cl = (CardLayout)(TelaRaiz.getLayout());
          
        cl.show(TelaRaiz, "telaAeroporto");
    }//GEN-LAST:event_telaAeroportosActionPerformed

    private void removerAeroPActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_removerAeroPActionPerformed
       RemAeroP remAeroP = new RemAeroP(dados);
       remAeroP.setVisible(true);
    }//GEN-LAST:event_removerAeroPActionPerformed

    private void adicionarAeroPActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_adicionarAeroPActionPerformed
        AddAeroP addAeroP = new AddAeroP(dados);
        addAeroP.setVisible(true);
    }//GEN-LAST:event_adicionarAeroPActionPerformed

    private void voltarARActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_voltarARActionPerformed
        CardLayout cl = (CardLayout)(TelaRaiz.getLayout());
        cl.show(TelaRaiz, "telaPrincipal");
    }//GEN-LAST:event_voltarARActionPerformed

    private void editarAeroPActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_editarAeroPActionPerformed
        System.out.println("asd");
        System.out.println(dados.aeroportos.size());
        EditarAeroP editarAeroP = new EditarAeroP(dados);
        editarAeroP.setVisible(true);
    }//GEN-LAST:event_editarAeroPActionPerformed

    private void buscarAeroPActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buscarAeroPActionPerformed
        BuscarAeroP buscaAeroP = new BuscarAeroP(dados);
        buscaAeroP.setVisible(true);
    }//GEN-LAST:event_buscarAeroPActionPerformed

    private void telaAeroportosMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_telaAeroportosMouseEntered
        ImageIcon b = new ImageIcon("imagens\\depoisAE.jpg");
        ImageIcon a = new ImageIcon("imagens\\antesAE.jpg");
        System.out.println("entrou muda imagem");
        telaAeroportos.setIcon(b);
        telaAeroportos.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_telaAeroportosMouseEntered

    private void telaAeroportosMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_telaAeroportosMouseExited
        ImageIcon b = new ImageIcon("imagens\\depoisAE.jpg");
        ImageIcon a = new ImageIcon("imagens\\antesAE.jpg");
        System.out.println("saiu volta");
        telaAeroportos.setIcon(a);
    }//GEN-LAST:event_telaAeroportosMouseExited

    private void telaVoosMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_telaVoosMouseEntered
        ImageIcon b = new ImageIcon("imagens\\depoisVO.jpg");
        ImageIcon a = new ImageIcon("imagens\\antesVOO.jpg");
        System.out.println("entrou muda imagem");
        telaVoos.setIcon(b);
        telaVoos.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_telaVoosMouseEntered

    private void telaVoosMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_telaVoosMouseExited
                                       
        ImageIcon b = new ImageIcon("imagens\\depoisVO.jpg");
        ImageIcon a = new ImageIcon("imagens\\antesVOO.jpg");
        System.out.println("entrou muda imagem");
        telaVoos.setIcon(a);
    }//GEN-LAST:event_telaVoosMouseExited

    private void telaClientesMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_telaClientesMouseClicked
        
    }//GEN-LAST:event_telaClientesMouseClicked

    
    private void telaClientesMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_telaClientesMouseExited
        ImageIcon b = new ImageIcon("imagens\\depoisCLIE.jpg");
        ImageIcon a = new ImageIcon("imagens\\antesCLIE.jpg");
        System.out.println("saiu cli muda imagem");
        telaClientes.setIcon(a);
    }//GEN-LAST:event_telaClientesMouseExited

    private void telaClientesMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_telaClientesMouseEntered
        ImageIcon b = new ImageIcon("imagens\\depoisCLIE.jpg");
        ImageIcon a = new ImageIcon("imagens\\antesCLIE.jpg");
        System.out.println("entrou cli muda imagem");
        telaClientes.setIcon(b);
        telaClientes.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_telaClientesMouseEntered

    private void buscarAeroPMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_buscarAeroPMouseEntered
        ImageIcon b = new ImageIcon("imagens\\procuradepois.png");
        ImageIcon a = new ImageIcon("imagens\\procura1.png");
        System.out.println("entrou cli muda imagem");
        buscarAeroP.setIcon(b);
        buscarAeroP.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_buscarAeroPMouseEntered

    private void buscarAeroPMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_buscarAeroPMouseExited
        ImageIcon b = new ImageIcon("imagens\\procuradepois.png");
        ImageIcon a = new ImageIcon("imagens\\procura1.png");
        System.out.println("saiu cli muda imagem");
        buscarAeroP.setIcon(a);
    }//GEN-LAST:event_buscarAeroPMouseExited

    private void jButton2MouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButton2MouseEntered
        ImageIcon b = new ImageIcon("imagens\\removeaviaodps.png");
        ImageIcon a = new ImageIcon("imagens\\removeaviao.png");
        System.out.println("entrou cli muda imagem");
        jButton2.setIcon(b);
        jButton2.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_jButton2MouseEntered

    private void jButton2MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButton2MouseExited
        ImageIcon b = new ImageIcon("imagens\\removeaviaodps.png");
        ImageIcon a = new ImageIcon("imagens\\removeaviao.png");
        System.out.println("saiu cli muda imagem");
        jButton2.setIcon(a);
    }//GEN-LAST:event_jButton2MouseExited

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
       RemAviao remaviao = new RemAviao(dados);
       remaviao.setVisible(true);
    }//GEN-LAST:event_jButton2ActionPerformed

    private void jButton1MouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButton1MouseEntered
        ImageIcon b = new ImageIcon("imagens\\editaraviaofinal.jpg");
        ImageIcon a = new ImageIcon("imagens\\editaraviao.jpg");
        System.out.println("entrou cli muda imagem");
        jButton1.setIcon(b);
        jButton1.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_jButton1MouseEntered

    private void jButton1MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButton1MouseExited
       ImageIcon b = new ImageIcon("imagens\\editaraviaofinal.jpg");
       ImageIcon a = new ImageIcon("imagens\\editaraviao.jpg");
       System.out.println("saiu cli muda imagem");
       jButton1.setIcon(a);
    }//GEN-LAST:event_jButton1MouseExited

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
       AddAviao addaviao = new AddAviao(dados);
       addaviao.setVisible(true);
    }//GEN-LAST:event_jButton1ActionPerformed

    private void editarAeroPMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_editarAeroPMouseEntered
        ImageIcon b = new ImageIcon("imagens\\baseaeroeditadepois.png");
        ImageIcon a = new ImageIcon("imagens\\baseaeroedita.png");
        System.out.println("entrou cli muda imagem");
        editarAeroP.setIcon(b);
        editarAeroP.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_editarAeroPMouseEntered

    private void editarAeroPMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_editarAeroPMouseExited
        ImageIcon b = new ImageIcon("imagens\\baseaeroeditadepois.png");
       ImageIcon a = new ImageIcon("imagens\\baseaeroedita.png");
       System.out.println("saiu cli muda imagem");
       editarAeroP.setIcon(a);
    }//GEN-LAST:event_editarAeroPMouseExited

    private void jButton3MouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButton3MouseEntered
        ImageIcon b = new ImageIcon("imagens\\baseaviaoeditadepois.png");
        ImageIcon a = new ImageIcon("imagens\\baseaviaoedita.png");
        System.out.println("entrou cli muda imagem");
        jButton3.setIcon(b);
        jButton3.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_jButton3MouseEntered

    private void jButton3MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButton3MouseExited
        ImageIcon b = new ImageIcon("imagens\\baseaviaoeditadepois.png");
       ImageIcon a = new ImageIcon("imagens\\baseaviaoedita.png");
       System.out.println("saiu cli muda imagem");
       jButton3.setIcon(a);
                             
    }//GEN-LAST:event_jButton3MouseExited

    private void removerAeroPMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_removerAeroPMouseEntered
       ImageIcon b = new ImageIcon("imagens\\baseremoveraerodepois.png");
        ImageIcon a = new ImageIcon("imagens\\baseremoveraero.png");
        System.out.println("entrou cli muda imagem");
        removerAeroP.setIcon(b);
        removerAeroP.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_removerAeroPMouseEntered

    private void removerAeroPMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_removerAeroPMouseExited
       ImageIcon b = new ImageIcon("imagens\\baseremoveraerodepois.png");
       ImageIcon a = new ImageIcon("imagens\\baseremoveraero.png");
       System.out.println("saiu cli muda imagem");
       removerAeroP.setIcon(a);
    }//GEN-LAST:event_removerAeroPMouseExited

    private void adicionarAeroPMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_adicionarAeroPMouseEntered
        ImageIcon b = new ImageIcon("imagens\\novoaeroportodepois.jpg");
        ImageIcon a = new ImageIcon("imagens\\novoaeroporto.jpg");
        System.out.println("entrou cli muda imagem");
        adicionarAeroP.setIcon(b);
        adicionarAeroP.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_adicionarAeroPMouseEntered

    private void adicionarAeroPMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_adicionarAeroPMouseExited
        ImageIcon b = new ImageIcon("imagens\\novoaeroportodepois.jpg");
       ImageIcon a = new ImageIcon("imagens\\novoaeroporto.jpg");
       System.out.println("saiu cli muda imagem");
       adicionarAeroP.setIcon(a);
    }//GEN-LAST:event_adicionarAeroPMouseExited

    private void telaVoosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_telaVoosActionPerformed
        CardLayout cl = (CardLayout)(TelaRaiz.getLayout());
          
        cl.show(TelaRaiz, "telaVoos");
    }//GEN-LAST:event_telaVoosActionPerformed

    
    //ESSE AQUI NA VERDADE EDITAR VOO
    private void editarVooMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_editarVooMouseEntered
         editarVoo.setToolTipText("Editar voo");
        editarVoo.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_editarVooMouseEntered

    private void editarVooMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_editarVooMouseExited
       
    }//GEN-LAST:event_editarVooMouseExited

    private void editarVooActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_editarVooActionPerformed
       EditarVoo editarvoo = new EditarVoo(dados);
       editarvoo.setVisible(true);
        
    }//GEN-LAST:event_editarVooActionPerformed

    //ESSE AQUI NA VERDADE REMOVER VOO
    private void remVooMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_remVooMouseEntered
        remVoo.setToolTipText("Remover voo");
       
        remVoo.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_remVooMouseEntered

    private void remVooMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_remVooMouseExited
        
    }//GEN-LAST:event_remVooMouseExited

    private void remVooActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_remVooActionPerformed
       RemVoo remvoo = new RemVoo(dados);
       remvoo.setVisible(true);
    }//GEN-LAST:event_remVooActionPerformed

    private void voltarVoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_voltarVoActionPerformed
        CardLayout cl = (CardLayout)(TelaRaiz.getLayout());
        cl.show(TelaRaiz, "telaPrincipal");
    }//GEN-LAST:event_voltarVoActionPerformed

    
 
    private void adicionarVooMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_adicionarVooMouseEntered
        ImageIcon b = new ImageIcon("imagens\\adicionarvoodepois.jpg");
        ImageIcon a = new ImageIcon("imagens\\adicionarvoo.jpg");
        System.out.println("entrou cli muda imagem");
        adicionarVoo.setIcon(b);
        adicionarVoo.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_adicionarVooMouseEntered

    private void adicionarVooMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_adicionarVooMouseExited
        ImageIcon b = new ImageIcon("imagens\\adicionarvoodepois.jpg");
       ImageIcon a = new ImageIcon("imagens\\adicionarvoo.jpg");
       System.out.println("saiu cli muda imagem");
       adicionarVoo.setIcon(a);
    }//GEN-LAST:event_adicionarVooMouseExited

    private void adicionarVooActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_adicionarVooActionPerformed
       AddVoo addvoo = new AddVoo(dados);
       addvoo.setVisible(true);
    }//GEN-LAST:event_adicionarVooActionPerformed

    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
       EditarAviao editaraviao = new EditarAviao(dados);
       editaraviao.setVisible(true);
    }//GEN-LAST:event_jButton3ActionPerformed

    private void reservasClienteMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_reservasClienteMouseEntered
        reservasCliente.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_reservasClienteMouseEntered

    private void reservasClienteMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_reservasClienteMouseExited
        // TODO add your handling code here:
    }//GEN-LAST:event_reservasClienteMouseExited

    private void reservasClienteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_reservasClienteActionPerformed
        CardLayout cl = (CardLayout)(TelaRaiz.getLayout());
        cl.show(TelaRaiz, "telaReservaCliente");
    }//GEN-LAST:event_reservasClienteActionPerformed

    private void voltarCliActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_voltarCliActionPerformed
         CardLayout cl = (CardLayout)(TelaRaiz.getLayout());
        cl.show(TelaRaiz, "telaPrincipal");
    }//GEN-LAST:event_voltarCliActionPerformed

    private void addClienteMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_addClienteMouseEntered
        addCliente.setToolTipText("Adicionar cliente");
        addCliente.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_addClienteMouseEntered

    private void addClienteMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_addClienteMouseExited
        // TODO add your handling code here:
    }//GEN-LAST:event_addClienteMouseExited

    private void addClienteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_addClienteActionPerformed
       AdicionarCliente add = new AdicionarCliente(dados);
       add.setVisible(true);
    }//GEN-LAST:event_addClienteActionPerformed

    private void editarClienteMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_editarClienteMouseEntered
        editarCliente.setToolTipText("Editar cliente");
        editarCliente.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_editarClienteMouseEntered

    private void editarClienteMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_editarClienteMouseExited
        // TODO add your handling code here:
    }//GEN-LAST:event_editarClienteMouseExited

    private void editarClienteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_editarClienteActionPerformed
       EditarCliente add = new EditarCliente(dados);
       add.setVisible(true);

    }//GEN-LAST:event_editarClienteActionPerformed

    private void remClienteMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_remClienteMouseEntered
        remCliente.setToolTipText("Remover cliente");
        remCliente.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_remClienteMouseEntered

    private void remClienteMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_remClienteMouseExited
        // TODO add your handling code here:
    }//GEN-LAST:event_remClienteMouseExited

    private void remClienteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_remClienteActionPerformed
       RemoverCliente add = new RemoverCliente(dados);
       add.setVisible(true);
    }//GEN-LAST:event_remClienteActionPerformed

    private void reservasVooMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_reservasVooMouseEntered
        reservasVoo.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_reservasVooMouseEntered

    private void reservasVooMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_reservasVooMouseExited
        // TODO add your handling code here:
    }//GEN-LAST:event_reservasVooMouseExited

    private void reservasVooActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_reservasVooActionPerformed
        CardLayout cl = (CardLayout)(TelaRaiz.getLayout());
        cl.show(TelaRaiz, "telaReservaVoo");
    }//GEN-LAST:event_reservasVooActionPerformed

    private void buscarCPFMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_buscarCPFMouseEntered
        buscarCPF.setToolTipText("Buscar cliente por CPF");
        buscarCPF.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_buscarCPFMouseEntered

    private void buscarCPFMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_buscarCPFMouseExited
        // TODO add your handling code here:
    }//GEN-LAST:event_buscarCPFMouseExited

    private void buscarCPFActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buscarCPFActionPerformed
         BuscarCliente buscavoo = new BuscarCliente(dados);
        buscavoo.setVisible(true);
        
    }//GEN-LAST:event_buscarCPFActionPerformed

    private void jButton5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton5ActionPerformed
        
        BuscarVoo buscavoo = new BuscarVoo(dados);
        buscavoo.setVisible(true);
    }//GEN-LAST:event_jButton5ActionPerformed

    private void jButton5MouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButton5MouseEntered
       jButton5.setToolTipText("Buscar voo");
        jButton5.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_jButton5MouseEntered

    private void jButton6MouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButton6MouseEntered
        jButton6.setToolTipText("Buscar voo por Cidade");
        jButton6.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_jButton6MouseEntered

    private void jButton6ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton6ActionPerformed
       BuscarVoo2 buscarvoo2 = new BuscarVoo2(dados);
       buscarvoo2.setVisible(true);
    }//GEN-LAST:event_jButton6ActionPerformed

    private void voltarCli1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_voltarCli1ActionPerformed
        CardLayout cl = (CardLayout)(TelaRaiz.getLayout());
        cl.show(TelaRaiz, "telaCliente");
    }//GEN-LAST:event_voltarCli1ActionPerformed

    private void addCliente1MouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_addCliente1MouseEntered
        addCliente1.setToolTipText("Incluir reserva de voo");
        addCliente1.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_addCliente1MouseEntered

    private void addCliente1MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_addCliente1MouseExited
        // TODO add your handling code here:
    }//GEN-LAST:event_addCliente1MouseExited

    private void addCliente1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_addCliente1ActionPerformed
       IncluirVoo buscarvoo2 = new IncluirVoo(dados);
       buscarvoo2.setVisible(true);
    }//GEN-LAST:event_addCliente1ActionPerformed

    private void reservasVoo1MouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_reservasVoo1MouseEntered
        // TODO add your handling code here:
    }//GEN-LAST:event_reservasVoo1MouseEntered

    private void reservasVoo1MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_reservasVoo1MouseExited
        // TODO add your handling code here:
    }//GEN-LAST:event_reservasVoo1MouseExited

    private void reservasVoo1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_reservasVoo1ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_reservasVoo1ActionPerformed

    private void remCliente1MouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_remCliente1MouseEntered
        addCliente1.setToolTipText("Remover reserva de cliente");
        addCliente1.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_remCliente1MouseEntered

    private void remCliente1MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_remCliente1MouseExited
        // TODO add your handling code here:
    }//GEN-LAST:event_remCliente1MouseExited

    private void remCliente1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_remCliente1ActionPerformed
        RemoverVooViagem buscarvoo2 = new RemoverVooViagem(dados);
       buscarvoo2.setVisible(true);     
        
        
    }//GEN-LAST:event_remCliente1ActionPerformed

    private void voltarCli2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_voltarCli2ActionPerformed
       CardLayout cl = (CardLayout)(TelaRaiz.getLayout());
        cl.show(TelaRaiz, "telaCliente");
    }//GEN-LAST:event_voltarCli2ActionPerformed

    private void addCliente2MouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_addCliente2MouseEntered
        addCliente1.setToolTipText("Incluir reserva de cliente");
        addCliente1.setCursor(new Cursor(Cursor.HAND_CURSOR));
    }//GEN-LAST:event_addCliente2MouseEntered

    private void addCliente2MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_addCliente2MouseExited
        // TODO add your handling code here:
    }//GEN-LAST:event_addCliente2MouseExited

    private void addCliente2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_addCliente2ActionPerformed
        AdicionarReservaCliente buscavoo = new AdicionarReservaCliente(dados);
        buscavoo.setVisible(true);
        
        
    }//GEN-LAST:event_addCliente2ActionPerformed

    private void reservasVoo2MouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_reservasVoo2MouseEntered
        // TODO add your handling code here:
    }//GEN-LAST:event_reservasVoo2MouseEntered

    private void reservasVoo2MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_reservasVoo2MouseExited
        // TODO add your handling code here:
    }//GEN-LAST:event_reservasVoo2MouseExited

    private void reservasVoo2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_reservasVoo2ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_reservasVoo2ActionPerformed

    private void remCliente2MouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_remCliente2MouseEntered
        // TODO add your handling code here:
    }//GEN-LAST:event_remCliente2MouseEntered

    private void remCliente2MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_remCliente2MouseExited
        // TODO add your handling code here:
    }//GEN-LAST:event_remCliente2MouseExited

    private void remCliente2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_remCliente2ActionPerformed
       RemoverReservaCliente buscarvoo2 = new RemoverReservaCliente(dados);
       buscarvoo2.setVisible(true);   
    }//GEN-LAST:event_remCliente2ActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(TelaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(TelaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(TelaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(TelaPrincipal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new TelaPrincipal().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JPanel AeroportoRaiz;
    private javax.swing.JPanel ClienteRaiz;
    private javax.swing.JPanel ReservasViagem;
    private javax.swing.JPanel ReservasVoo;
    private javax.swing.JPanel TelaRaiz;
    private javax.swing.JPanel VooRaiz;
    private javax.swing.JButton addCliente;
    private javax.swing.JButton addCliente1;
    private javax.swing.JButton addCliente2;
    private javax.swing.JButton adicionarAeroP;
    private javax.swing.JButton adicionarVoo;
    private javax.swing.JButton buscarAeroP;
    private javax.swing.JButton buscarCPF;
    private javax.swing.JButton editarAeroP;
    private javax.swing.JButton editarCliente;
    private javax.swing.JButton editarVoo;
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton4;
    private javax.swing.JButton jButton5;
    private javax.swing.JButton jButton6;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JButton remCliente;
    private javax.swing.JButton remCliente1;
    private javax.swing.JButton remCliente2;
    private javax.swing.JButton remVoo;
    private javax.swing.JButton removerAeroP;
    private javax.swing.JButton reservasCliente;
    private javax.swing.JButton reservasVoo;
    private javax.swing.JButton reservasVoo1;
    private javax.swing.JButton reservasVoo2;
    private javax.swing.JButton telaAeroportos;
    private javax.swing.JButton telaClientes;
    private javax.swing.JPanel telaPrincipal;
    private javax.swing.JButton telaVoos;
    private javax.swing.JButton voltarAR;
    private javax.swing.JButton voltarCli;
    private javax.swing.JButton voltarCli1;
    private javax.swing.JButton voltarCli2;
    private javax.swing.JButton voltarVo;
    // End of variables declaration//GEN-END:variables
}
