<html>
<head>
    <%@ include file="/static/jsp/headInclude.jsp" %>
</head><!--/head-->
<body>
<%@ include file="/static/jsp/elements/header.jsp" %>

<section>
    <div class="container">
        <div class="row">
            <%@ include file="/static/jsp/elements/productCategories.jsp" %>

            <div class="col-sm-9 padding-right">
                <div class="features_items">
                    <h2 class="title text-center"><c:out value="${title}"/></h2>
                    <c:forEach items="${products}" var="product" varStatus="status">
                        <c:if test="${product.active == true}">
                            <div class="col-sm-4">
                                <div class="product-image-wrapper">
                                    <div class="single-products">
                                        <div class="productinfo text-center">
                                            <img src="<c:out value='${product.illustration}'/>" alt="" />
                                            <h2>$<c:out value="${product.price}"/></h2>
                                            <p><c:out value="${product.name}"/></p>
                                            <a href="/addtocart/<c:out value='${product.id}'/>" class="btn btn-default add-to-cart"><i class="fa fa-shopping-cart"></i>Add to cart</a>
                                        </div>
                                        <div class="product-overlay">
                                            <div class="overlay-content">
                                                <h2>$<c:out value="${product.price}"/></h2>
                                                <p><c:out value="${product.name}"/></p>
                                                <a href="/addtocart/<c:out value='${product.id}'/>" class="btn btn-default add-to-cart"><i class="fa fa-shopping-cart"></i>Add to cart</a>
                                            </div>
                                        </div>
                                    </div>
                                    <div class="choose">
                                        <ul class="nav nav-pills nav-justified">
                                            <li><a href="/product/<c:out value='${product.id}'/>"><i class="fa fa-plus-square"></i>Display product</a></li>
                                        </ul>
                                    </div>
                                </div>
                            </div>
                        </c:if>
                    </c:forEach>
                </div>
            </div>
        </div>
    </div>
</section>
<%-- MODAL NEWSLETTER --%>

<!-- Modal -->
<div class="modal fade in" id="myModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel">
    <div class="modal-dialog" role="document">
        <div class="modal-content">
            <div class="modal-header">
                <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                <h4 class="modal-title" id="myModalLabel">Newsletter subscription</h4>
            </div>
            <form action="home" method="POST">
                <div class="modal-body">
                    <input type="email" style="width: 100%" placeholder="Email Address" name="email" required/>
                </div>
                <div class="modal-footer">
                    <button type="button" class="btn btn-primary" data-dismiss="modal">Close</button>
                    <button type="submit" class="btn btn-primary" name="newsletter" value="Newsletter">Subscribe</button>
                </div>
            </form>
        </div>
    </div>
</div>

<%@ include file="/static/jsp/elements/footer.jsp" %>
<%@ include file="/static/jsp/JSinclude.jsp" %>

<c:if test="${sessionScope.newsletter == null && sessionScope.user == null}">
    <script type="text/javascript">
        $(window).load(function(){
            $('#myModal').modal('show');
        });
    </script>
</c:if>
<script type="text/javascript">
    $(window).load(function() {
        $('#myModal').on('hidden', function() {
            console.log("debug");
            <c:set var="newsletter" value="${true}" scope="session"  />
        });
    });
</script>
</body>
</html>