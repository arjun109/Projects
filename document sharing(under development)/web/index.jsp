<%-- 
    Document   : index
    Created on : Apr 9, 2012, 12:48:26 PM
    Author     : lucky
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
       <FORM  ENCTYPE="multipart/form-data" ACTION="single_upload_page.jsp" METHOD=POST>
                <br><br><br>
          <center><table border="2" >
                    <tr><center><td colspan="2"><p align=
"center"><B>PROGRAM FOR UPLOADING THE FILE</B></center></tr>
                    <tr><td><b>Choose the file To Upload:</b>
</td>
                    <td><INPUT NAME="F1" TYPE="file"></td></tr>
                                        <tr><td colspan="2">
<p align="right"><INPUT TYPE="submit" VALUE="Send File" ></p></td></tr>
             </table>
     </center>
     </FORM>
        
    </body>
</html>
