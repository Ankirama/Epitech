package com.jweb.servlet.utils;

import javax.mail.*;
import javax.mail.internet.AddressException;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;
import java.util.ArrayList;
import java.util.Properties;

/**
 * Created by ankirama on 14/12/15.
 */
public class SendEmail {
    private static String host = "weezyu.com";
    private static String port = "587";
    private static String from = "e-shopper@weezyu.com";
    private static String pass = "pommealapoele";
    private static Properties properties = System.getProperties();

    /**
     * set properties
     * @return {Properties}
     */
    private static Properties setProperties() {
        properties.setProperty("mail.smtp.starttls.enable", "true");
        properties.setProperty("mail.smtp.ssl.trust", host);
        properties.setProperty("mail.smtp.host", host);
        properties.setProperty("mail.smtp.user", from);
        properties.setProperty("mail.smtp.password", pass);
        properties.setProperty("mail.smtp.port", port);
        properties.setProperty("mail.smtp.auth", "true");
        return properties;
    }

    /**
     * Send an email to our mainEmail
     * @param email from email to contact us
     * @param subject subject in our email
     * @param content content in our email, in plain text mode
     * @return {boolean}
     */
    public static boolean sendMailViaContact(String email, String subject, String content) {

        Session session = Session.getDefaultInstance(setProperties());
        try {
            MimeMessage message = new MimeMessage(session);
            message.setFrom(new InternetAddress(from));
            message.addRecipient(Message.RecipientType.TO, new InternetAddress(from));
            message.setSubject("[" + email + "] " + subject);
            message.setText(content);
            Transport transport = session.getTransport("smtp");
            transport.connect(host, from, pass);
            transport.sendMessage(message, message.getAllRecipients());
            transport.close();
            return true;
        } catch (MessagingException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * Send an email to our mainEmail
     * @param subject subject in our email
     * @param content content in our email, in plain text mode
     * @return {boolean}
     */
    public static boolean sendMailViaContact(String subject, String content) {

        Session session = Session.getDefaultInstance(setProperties());
        try {
            MimeMessage message = new MimeMessage(session);
            message.setFrom(new InternetAddress(from));
            message.addRecipient(Message.RecipientType.TO, new InternetAddress(from));
            message.setSubject(subject);
            message.setText(content);
            Transport transport = session.getTransport("smtp");
            transport.connect(host, from, pass);
            transport.sendMessage(message, message.getAllRecipients());
            transport.close();
            return true;
        } catch (MessagingException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * Send an email to validate creation mail
     * @param email email receiver
     * @param subject subject in our email
     * @param content content in our email, in plain text mode
     * @return {boolean}
     */
    public static boolean sendMailValidation(String email, String subject, String content) {

        Session session = Session.getDefaultInstance(setProperties());
        try {
            MimeMessage message = new MimeMessage(session);
            message.setFrom(new InternetAddress(from));
            message.addRecipient(Message.RecipientType.TO, new InternetAddress(email));
            message.setSubject(subject);
            message.setText(content);
            Transport transport = session.getTransport("smtp");
            transport.connect(host, from, pass);
            transport.sendMessage(message, message.getAllRecipients());
            transport.close();
            return true;
        } catch (MessagingException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }

    /**
     * Send news to newsletter users
     * @param emails all users email
     * @param subject news' subject
     * @param content news' content
     * @return {boolean}
     */
    public static boolean sendNewsToUsers(ArrayList<String> emails, String subject, String content) {
        Session session = Session.getDefaultInstance(setProperties());
        if (emails.size() == 0) return false;
        InternetAddress[] address = new InternetAddress[emails.size()];

        try {
            for (int i = 0; i < emails.size(); ++i) {
                address[i] = new InternetAddress(emails.get(i));
            }
            MimeMessage message = new MimeMessage(session);
            message.setFrom(new InternetAddress(from));
            message.addRecipient(Message.RecipientType.TO, new InternetAddress(from));
            message.addRecipients(Message.RecipientType.BCC, address);
            message.setSubject(subject);
            message.setText(content);
            Transport transport = session.getTransport("smtp");
            transport.connect(host, from, pass);
            transport.sendMessage(message, message.getAllRecipients());
            transport.close();
            return true;
        } catch (MessagingException e) {
            System.err.println(e.getMessage());
            return false;
        }
    }
}
