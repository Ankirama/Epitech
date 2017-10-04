<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <%@ include file="/static/jsp/headInclude.jsp" %>
</head><!--/head-->
<body>
<%@ include file="/static/jsp/elements/header.jsp" %>
<section>
    <div class="container">
        <div class="row">
            <%@ include file="/static/jsp/elements/accountCategories.jsp" %>
            <div class="col-sm-9 padding-right">
                <h2 class="title text-center">Create new address</h2>
                <div class="col-sm-6 col-sm-offset-3 login-form">
                    <form action="newAddress" method="POST">
                        <input type="text" placeholder="Name" name="name" required/>
                        <input type="text" placeholder="First Name" name="firstName" required/>
                        <input type="text" placeholder="Last Name" name="lastName" required/>
                        <input type="text" placeholder="Address1" name="address1" required/>
                        <input type="text" placeholder="Address2" name="address2" />
                        <input type="text" placeholder="Country" name="country" required/>
                        <input type="text" placeholder="City" name="city" required/>
                        <div>
                            <button type="submit" name="create" value="Create" class="btn btn-default">Add address</button>
                        </div>
                    </form>
                </div>
            </div>
        </div>
    </div>
</section>
<%@ include file="/static/jsp/elements/footer.jsp" %>
<%@ include file="/static/jsp/JSinclude.jsp" %>
</body>
</html>
