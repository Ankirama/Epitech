<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <%@ include file="/static/jsp/headInclude.jsp" %>
</head><!--/head-->
<body>
<%@ include file="/static/jsp/elements/header.jsp" %>
<div class="container">
    <div class="row">
        <%@ include file="/static/jsp/elements/productCategories.jsp" %>
        <div class="col-sm-9 padding-right">

            <div class="product-details"><!--product-details-->
                <div class="col-sm-5">
                    <div class="view-product">
                        <img src="<c:out value='${product.illustration}'/>" alt="" />
                    </div>
                </div>
                <div class="col-sm-7">
                    <div class="product-information"><!--/product-information-->
                        <h2><c:out value="${product.name}"/></h2>
                        <p>Web ID: <c:out value="${product.id}"/></p>
                        <span>
                            <span>US $<c:out value="${product.price}"/></span>
                            <form action="/addtocart" method="POST">
                                <label>Quantity:</label>
                                <input type="number" value="1" name="quantity" min="0" max="10" />
                                <input type="hidden" value="${product.id}" name="productid"/>
                                <button type="submit" class="btn btn-fefault cart">
                                    <i class="fa fa-shopping-cart"></i>
                                    Add to cart
                                </button>
                            </form>
                        </span>
                        <p><b>Availability:</b> In Stock</p>
                    </div><!--/product-information-->
                </div>
            </div><!--/product-details-->

            <div class="category-tab shop-details-tab"><!--category-tab-->
                <div class="col-sm-12">
                    <ul class="nav nav-tabs">
                        <li><a href="#details" data-toggle="tab">Details</a></li>
                        <li class="active"><a href="#reviews" data-toggle="tab">Reviews (<c:out value="${opinions.size()}"/>)</a></li>
                    </ul>
                </div>
                <div class="tab-content">
                    <div class="tab-pane fade" id="details" >
                        <p><c:out value="${product.description}"/></p>
                    </div>

                    <div class="tab-pane fade active in" id="reviews" >
                        <div class="col-sm-12">
                            <c:forEach items="${opinions}" var="opinion" varStatus="status">
                                <ul>
                                    <li><i class="fa fa-user"></i><c:out value="${opinion.author}"/></li>
                                </ul>
                                <p><c:out value="${opinion.comment}"/></p>
                                    <br />
                                    <br />
                                    <br />
                            </c:forEach>
                            <p><b>Write Your Review</b></p>
                            <form action="/addOpinion" method="POST">
                                <span style="margin-left: -10px!important;">
                                    <input type="text" placeholder="Your Name" name="author" required/>
                                </span>
                                <textarea name="content" required></textarea>
                                <input type="hidden" name="productid" value="<c:out value='${product.id}'/>" />
                                <button type="submit" class="btn btn-default pull-right" value="submit">
                                    Submit
                                </button>
                            </form>
                        </div>
                    </div>

                </div>
            </div><!--/category-tab-->
        </div>
    </div>
</div>

<%@ include file="/static/jsp/elements/footer.jsp" %>
<%@ include file="/static/jsp/JSinclude.jsp" %>

</body>
</html>

