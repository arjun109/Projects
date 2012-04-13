import java.io.*;
import java.net.*;
import java.util.*;/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author lucky
 */
public class webserver {
public static void main(String argv[]) throws Exception {
 String requestMessageLine;
 String fileName;

 ServerSocket listenSocket = new ServerSocket(6789);
 while(true)
{
 Socket connectionSocket = listenSocket.accept();
 BufferedReader inFromClient =new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));

 DataOutputStream outToClient =new DataOutputStream(connectionSocket.getOutputStream());

 requestMessageLine = inFromClient.readLine();
 StringTokenizer tokenizedLine =new StringTokenizer(requestMessageLine);

if (tokenizedLine.nextToken().equals("GET"))
{
    fileName = tokenizedLine.nextToken();
    if (fileName.startsWith("/") == true )
    fileName = fileName.substring(1);
    File file = new File(fileName);
    System.out.println("Abs Path:" + file.getAbsolutePath());
    int numOfBytes = (int) file.length();
    FileInputStream inFile = new FileInputStream (fileName);
    byte[] fileInBytes = new byte[numOfBytes];
    inFile.read(fileInBytes);
    outToClient.writeBytes("HTTP/1.0 200 Document Follows\r\n");
    if (fileName.endsWith(".jpg"))
    outToClient.writeBytes("Content-Type: image/jpeg\r\n");

    if (fileName.endsWith(".gif"))
    outToClient.writeBytes("Content-Type: image/gif\r\n");

    if (fileName.endsWith(".pdf"))
    outToClient.writeBytes("Content-Type: application/pdf\r\n");

    if (fileName.endsWith(".mp4"))
    outToClient.writeBytes("Content-Type: video/mp4\r\n");


    outToClient.writeBytes("Content-Length: " + numOfBytes + "\r\n");

    outToClient.writeBytes("\r\n");
    outToClient.write(fileInBytes, 0, numOfBytes);
    
    connectionSocket.close();

}
else System.out.println("Bad Request Message");
    }
}
    }

