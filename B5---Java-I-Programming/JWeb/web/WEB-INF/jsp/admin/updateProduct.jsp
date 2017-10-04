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
            <%@ include file="/static/jsp/elements/adminCategories.jsp" %>
            <div class="col-sm-9 padding-right">
                <h2 class="title text-center">Update product</h2>
                <div class="col-sm-6 col-sm-offset-3">
                    <div class="contact-form">
                        <form id="main-contact-form" class="contact-form row" action="updateProduct" name="contact-form" method="POST">
                            <div class="form-group col-md-12">
                                <input type="text" name="name" value="${product.name}" class="form-control" required="required" placeholder="Name">
                            </div>
                            <div class="form-group col-md-12">
                                <select name="categoryid" class="form-control" required="required">
                                    <c:forEach items="${categories}" var="category">
                                        <option <c:if test="${category.id == product.categoryid}">selected</c:if> value="${category.id}"><c:out value="${category.name}"/></option>
                                    </c:forEach>
                                </select>
                            </div>
                            <div class="form-group col-md-12">
                                Price ($):
                                <input type="number" name="price" value="${product.price}" class="form-control" min="0">
                            </div>
                            <div class="form-group col-md-12">
                                <textarea name="description" id="description" required="required" class="form-control" rows="3" placeholder="Description here."><c:out value="${product.description}"/></textarea>
                            </div>
                            <input type="hidden" value="${product.illustration}" name="illustration"/>
                            <input type="hidden" value="${product.id}" name="productid"/>
                            <div class="form-group col-md-12">
                                <input type="submit" name="submit" class="btn btn-primary pull-right" value="Update product">
                            </div>
                        </form>
                    </div>
                </div>
            </div>
        </div>
    </div>
</section>
<%@ include file="/static/jsp/elements/footer.jsp" %>
<%@ include file="/static/jsp/JSinclude.jsp" %>
</body>
</html>