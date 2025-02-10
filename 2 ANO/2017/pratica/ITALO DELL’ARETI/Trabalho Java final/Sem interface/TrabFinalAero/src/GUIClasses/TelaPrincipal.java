package GUIClasses;

import GUIClasses.aeroporto.AddAeroP;
import GUIClasses.aeroporto.BuscarAeroP;
import GUIClasses.aeroporto.EditarAeroP;
import GUIClasses.aeroporto.RemAeroP;
import GUIClasses.aviao.AddAviao;
import GUIClasses.aviao.EditarAviao;
import GUIClasses.aviao.RemAviao;
import GUIClasses.voo.AddVoo;
import GUIClasses.voo.EditarVoo;
import GUIClasses.voo.RemVoo;
import MainClasses.AllData;
import java.awt.CardLayout;

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

        TelaRaiz = new javax.swing.JPanel();
        telaPrincipal = new javax.swing.JPanel();
        telaClientes = new javax.swing.JButton();
        telaVoos = new javax.swing.JButton();
        telaAeroportos = new javax.swing.JButton();
        AeroportoRaiz = new javax.swing.JPanel();
        removerAeroP = new javax.swing.JButton();
        editarAeroP = new javax.swing.JButton();
        adicionarAeroP = new javax.swing.JButton();
        voltarAR = new javax.swing.JButton();
        buscarAeroP = new javax.swing.JButton();
        adicionarAviao = new javax.swing.JButton();
        removerAviao = new javax.swing.JButton();
        editarAviao = new javax.swing.JButton();
        VoosRaiz = new javax.swing.JPanel();
        adicionarVoo = new javax.swing.JButton();
        editarVoo = new javax.swing.JButton();
        removerVoo = new javax.swing.JButton();
        voltarVR = new javax.swing.JButton();
        ClientesRaiz = new javax.swing.JPanel();
        adicionarCliente = new javax.swing.JButton();
        editarCliente = new javax.swing.JButton();
        removerCliente = new javax.swing.JButton();
        criarViagem = new javax.swing.JButton();
        removerViagem = new javax.swing.JButton();
        voltarVC = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        TelaRaiz.setLayout(new java.awt.CardLayout());

        telaClientes.setText("Clientes");
        telaClientes.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                telaClientesActionPerformed(evt);
            }
        });

        telaVoos.setText("Voos");
        telaVoos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                telaVoosActionPerformed(evt);
            }
        });

        telaAeroportos.setText("Aeroportos");
        telaAeroportos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                telaAeroportosActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout telaPrincipalLayout = new javax.swing.GroupLayout(telaPrincipal);
        telaPrincipal.setLayout(telaPrincipalLayout);
        telaPrincipalLayout.setHorizontalGroup(
            telaPrincipalLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(telaPrincipalLayout.createSequentialGroup()
                .addGap(62, 62, 62)
                .addComponent(telaClientes, javax.swing.GroupLayout.PREFERRED_SIZE, 84, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(telaVoos, javax.swing.GroupLayout.PREFERRED_SIZE, 82, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(telaAeroportos)
                .addContainerGap(66, Short.MAX_VALUE))
        );
        telaPrincipalLayout.setVerticalGroup(
            telaPrincipalLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(telaPrincipalLayout.createSequentialGroup()
                .addGap(95, 95, 95)
                .addGroup(telaPrincipalLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(telaVoos, javax.swing.GroupLayout.PREFERRED_SIZE, 143, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(telaClientes, javax.swing.GroupLayout.PREFERRED_SIZE, 143, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(telaAeroportos, javax.swing.GroupLayout.PREFERRED_SIZE, 143, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(62, Short.MAX_VALUE))
        );

        TelaRaiz.add(telaPrincipal, "telaPrincipal");

        removerAeroP.setText("Remover AeroP");
        removerAeroP.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                removerAeroPActionPerformed(evt);
            }
        });

        editarAeroP.setText("Editar AeroP");
        editarAeroP.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                editarAeroPActionPerformed(evt);
            }
        });

        adicionarAeroP.setText("Novo AeroP");
        adicionarAeroP.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                adicionarAeroPActionPerformed(evt);
            }
        });

        voltarAR.setText("Voltar");
        voltarAR.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                voltarARActionPerformed(evt);
            }
        });

        buscarAeroP.setText("Procurar AeroP");
        buscarAeroP.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buscarAeroPActionPerformed(evt);
            }
        });

        adicionarAviao.setText("Adicionar Avião");
        adicionarAviao.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                adicionarAviaoActionPerformed(evt);
            }
        });

        removerAviao.setText("Remover Avião");
        removerAviao.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                removerAviaoActionPerformed(evt);
            }
        });

        editarAviao.setText("Editar Avião");
        editarAviao.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                editarAviaoActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout AeroportoRaizLayout = new javax.swing.GroupLayout(AeroportoRaiz);
        AeroportoRaiz.setLayout(AeroportoRaizLayout);
        AeroportoRaizLayout.setHorizontalGroup(
            AeroportoRaizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(AeroportoRaizLayout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(voltarAR)
                .addContainerGap())
            .addGroup(AeroportoRaizLayout.createSequentialGroup()
                .addGap(28, 28, 28)
                .addGroup(AeroportoRaizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(AeroportoRaizLayout.createSequentialGroup()
                        .addComponent(buscarAeroP, javax.swing.GroupLayout.PREFERRED_SIZE, 204, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(adicionarAeroP, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGroup(AeroportoRaizLayout.createSequentialGroup()
                        .addComponent(editarAeroP)
                        .addGap(16, 16, 16)
                        .addComponent(removerAeroP)
                        .addGap(18, 18, 18)
                        .addComponent(adicionarAviao))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, AeroportoRaizLayout.createSequentialGroup()
                        .addComponent(editarAviao, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGap(18, 18, 18)
                        .addComponent(removerAviao, javax.swing.GroupLayout.PREFERRED_SIZE, 161, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(48, Short.MAX_VALUE))
        );
        AeroportoRaizLayout.setVerticalGroup(
            AeroportoRaizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(AeroportoRaizLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(voltarAR)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(AeroportoRaizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(buscarAeroP, javax.swing.GroupLayout.PREFERRED_SIZE, 71, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(adicionarAeroP, javax.swing.GroupLayout.PREFERRED_SIZE, 72, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(AeroportoRaizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(editarAeroP, javax.swing.GroupLayout.PREFERRED_SIZE, 74, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(removerAeroP, javax.swing.GroupLayout.PREFERRED_SIZE, 74, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(adicionarAviao, javax.swing.GroupLayout.PREFERRED_SIZE, 71, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(AeroportoRaizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(editarAviao, javax.swing.GroupLayout.DEFAULT_SIZE, 71, Short.MAX_VALUE)
                    .addComponent(removerAviao, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(14, Short.MAX_VALUE))
        );

        TelaRaiz.add(AeroportoRaiz, "telaAeroporto");

        adicionarVoo.setText("Adicionar Voo");
        adicionarVoo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                adicionarVooActionPerformed(evt);
            }
        });

        editarVoo.setText("Editar Voo");
        editarVoo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                editarVooActionPerformed(evt);
            }
        });

        removerVoo.setText("Remover Voo");
        removerVoo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                removerVooActionPerformed(evt);
            }
        });

        voltarVR.setText("Voltar");
        voltarVR.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                voltarVRActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout VoosRaizLayout = new javax.swing.GroupLayout(VoosRaiz);
        VoosRaiz.setLayout(VoosRaizLayout);
        VoosRaizLayout.setHorizontalGroup(
            VoosRaizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(VoosRaizLayout.createSequentialGroup()
                .addGap(26, 26, 26)
                .addComponent(adicionarVoo)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(editarVoo)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(removerVoo)
                .addContainerGap(96, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, VoosRaizLayout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(voltarVR)
                .addContainerGap())
        );
        VoosRaizLayout.setVerticalGroup(
            VoosRaizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(VoosRaizLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(voltarVR)
                .addGap(111, 111, 111)
                .addGroup(VoosRaizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(adicionarVoo)
                    .addComponent(editarVoo)
                    .addComponent(removerVoo))
                .addContainerGap(137, Short.MAX_VALUE))
        );

        TelaRaiz.add(VoosRaiz, "telaVoo");

        adicionarCliente.setText("addCliente");
        adicionarCliente.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                adicionarClienteActionPerformed(evt);
            }
        });

        editarCliente.setText("editarCliente");

        removerCliente.setText("removerCliente");

        criarViagem.setText("Criar Viagem");

        removerViagem.setText("Remover Viagem");

        voltarVC.setText("Voltar");
        voltarVC.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                voltarVCActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout ClientesRaizLayout = new javax.swing.GroupLayout(ClientesRaiz);
        ClientesRaiz.setLayout(ClientesRaizLayout);
        ClientesRaizLayout.setHorizontalGroup(
            ClientesRaizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(ClientesRaizLayout.createSequentialGroup()
                .addGap(57, 57, 57)
                .addGroup(ClientesRaizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(ClientesRaizLayout.createSequentialGroup()
                        .addComponent(adicionarCliente)
                        .addGap(18, 18, 18)
                        .addComponent(editarCliente)
                        .addGap(18, 18, 18)
                        .addComponent(removerCliente))
                    .addGroup(ClientesRaizLayout.createSequentialGroup()
                        .addComponent(criarViagem)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(removerViagem)))
                .addContainerGap(43, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, ClientesRaizLayout.createSequentialGroup()
                .addGap(0, 0, Short.MAX_VALUE)
                .addComponent(voltarVC))
        );
        ClientesRaizLayout.setVerticalGroup(
            ClientesRaizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(ClientesRaizLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(voltarVC)
                .addGap(35, 35, 35)
                .addGroup(ClientesRaizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(adicionarCliente)
                    .addComponent(editarCliente)
                    .addComponent(removerCliente))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 66, Short.MAX_VALUE)
                .addGroup(ClientesRaizLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(criarViagem)
                    .addComponent(removerViagem))
                .addGap(124, 124, 124))
        );

        TelaRaiz.add(ClientesRaiz, "telaCliente");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addGap(0, 0, Short.MAX_VALUE)
                .addComponent(TelaRaiz, javax.swing.GroupLayout.PREFERRED_SIZE, 417, javax.swing.GroupLayout.PREFERRED_SIZE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(TelaRaiz, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

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
        EditarAeroP editarAeroP = new EditarAeroP(dados);
        editarAeroP.setVisible(true);
    }//GEN-LAST:event_editarAeroPActionPerformed

    private void buscarAeroPActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buscarAeroPActionPerformed
        BuscarAeroP buscaAeroP = new BuscarAeroP(dados);
        buscaAeroP.setVisible(true);
    }//GEN-LAST:event_buscarAeroPActionPerformed

    private void adicionarAviaoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_adicionarAviaoActionPerformed
       AddAviao addAviao = new AddAviao(dados);
       addAviao.setVisible(true);
    }//GEN-LAST:event_adicionarAviaoActionPerformed

    private void editarAviaoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_editarAviaoActionPerformed
       EditarAviao editarAviao = new EditarAviao(dados);
       editarAviao.setVisible(true);
    }//GEN-LAST:event_editarAviaoActionPerformed

    private void removerAviaoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_removerAviaoActionPerformed
       RemAviao remAviao = new RemAviao(dados);
       remAviao.setVisible(true);
    }//GEN-LAST:event_removerAviaoActionPerformed

    private void telaVoosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_telaVoosActionPerformed
        CardLayout cl = (CardLayout)(TelaRaiz.getLayout());
        cl.show(TelaRaiz, "telaVoo");
    }//GEN-LAST:event_telaVoosActionPerformed

    private void adicionarVooActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_adicionarVooActionPerformed
       AddVoo addVoo = new AddVoo(dados);
       addVoo.setVisible(true);
    }//GEN-LAST:event_adicionarVooActionPerformed

    private void voltarVRActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_voltarVRActionPerformed
        CardLayout cl = (CardLayout)(TelaRaiz.getLayout());
        cl.show(TelaRaiz, "telaPrincipal");
    }//GEN-LAST:event_voltarVRActionPerformed

    private void voltarVCActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_voltarVCActionPerformed
        CardLayout cl = (CardLayout)(TelaRaiz.getLayout());
        cl.show(TelaRaiz, "telaPrincipal");
    }//GEN-LAST:event_voltarVCActionPerformed

    private void adicionarClienteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_adicionarClienteActionPerformed
    }//GEN-LAST:event_adicionarClienteActionPerformed

    private void removerVooActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_removerVooActionPerformed
       RemVoo remVoo = new RemVoo(dados);
       remVoo.setVisible(true);
    }//GEN-LAST:event_removerVooActionPerformed

    private void editarVooActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_editarVooActionPerformed
       EditarVoo editarVoo = new EditarVoo(dados);
       editarVoo.setVisible(true);
    }//GEN-LAST:event_editarVooActionPerformed

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

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new TelaPrincipal().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JPanel AeroportoRaiz;
    private javax.swing.JPanel ClientesRaiz;
    private javax.swing.JPanel TelaRaiz;
    private javax.swing.JPanel VoosRaiz;
    private javax.swing.JButton adicionarAeroP;
    private javax.swing.JButton adicionarAviao;
    private javax.swing.JButton adicionarCliente;
    private javax.swing.JButton adicionarVoo;
    private javax.swing.JButton buscarAeroP;
    private javax.swing.JButton criarViagem;
    private javax.swing.JButton editarAeroP;
    private javax.swing.JButton editarAviao;
    private javax.swing.JButton editarCliente;
    private javax.swing.JButton editarVoo;
    private javax.swing.JButton removerAeroP;
    private javax.swing.JButton removerAviao;
    private javax.swing.JButton removerCliente;
    private javax.swing.JButton removerViagem;
    private javax.swing.JButton removerVoo;
    private javax.swing.JButton telaAeroportos;
    private javax.swing.JButton telaClientes;
    private javax.swing.JPanel telaPrincipal;
    private javax.swing.JButton telaVoos;
    private javax.swing.JButton voltarAR;
    private javax.swing.JButton voltarVC;
    private javax.swing.JButton voltarVR;
    // End of variables declaration//GEN-END:variables
}
