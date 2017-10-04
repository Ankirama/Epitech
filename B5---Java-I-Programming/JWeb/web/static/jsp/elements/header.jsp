<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<header id="header"><!--header-->
    <div class="header_top"><!--header_top-->
        <div class="container">
            <div class="row">
                <div class="col-sm-6">
                    <div class="contactinfo">
                        <ul class="nav nav-pills">
                            <li><a href="#"><i class="fa fa-phone"></i> +33 6 42 42 42 42</a></li>
                            <li><a href="mailto:e-shopper@weezyu.com"><i class="fa fa-envelope"></i> contact@e-shopper.com</a></li>
                        </ul>
                    </div>
                </div>
                <%--<div class="col-sm-6">--%>
                    <%--<div class="social-icons pull-right">--%>
                        <%--<ul class="nav navbar-nav">--%>
                            <%--<li><a href=""><i class="fa fa-facebook"></i></a></li>--%>
                            <%--<li><a href=""><i class="fa fa-twitter"></i></a></li>--%>
                            <%--<li><a href=""><i class="fa fa-linkedin"></i></a></li>--%>
                            <%--<li><a href=""><i class="fa fa-dribbble"></i></a></li>--%>
                            <%--<li><a href=""><i class="fa fa-google-plus"></i></a></li>--%>
                        <%--</ul>--%>
                    <%--</div>--%>
                <%--</div>--%>
            </div>
        </div>
    </div><!--/header_top-->

    <div class="header-middle"><!--header-middle-->
        <div class="container">
            <div class="row">
                <div class="col-sm-4">
                    <div class="logo pull-left">
                        <a href="/home"><img src="/static/images/home/logo.png" alt="" /></a>
                    </div>
                </div>
                <div class="col-sm-8">
                    <div class="shop-menu pull-right">
                        <ul class="nav navbar-nav">
                            <c:if test="${sessionScope.user != null}"><li>
                                <c:choose>
                                    <c:when test="${sessionScope.user.admin}">
                                    <a href="/admin"><i class="fa fa-user"></i><c:out value=" ${sessionScope.user.username}"/></a></li>
                                    </c:when>
                                    <c:otherwise>
                                        <a href="/account"><i class="fa fa-user"></i><c:out value=" ${sessionScope.user.username}"/></a></li>
                                    </c:otherwise>
                                </c:choose>
                            </c:if>
                            <li><a href="/cart"><i class="fa fa-shopping-cart"></i> Cart</a></li>
                            <c:if test="${sessionScope.user == null}"><li><a href="/login" class="active"><i class="fa fa-lock"></i> Login</a></li></c:if>
                            <c:if test="${sessionScope.user != null}"><li><a href="/logout" class="active"><i class="fa fa-lock"></i> Logout</a></li></c:if>
                        </ul>
                    </div>
                </div>
            </div>
        </div>
    </div><!--/header-middle-->

    <div class="header-bottom"><!--header-bottom-->
        <div class="container">
            <div class="row">
                <div class="col-sm-9">
                    <div class="navbar-header">
                        <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
                            <span class="sr-only">Toggle navigation</span>
                            <span class="icon-bar"></span>
                            <span class="icon-bar"></span>
                            <span class="icon-bar"></span>
                        </button>
                    </div>
                    <div class="mainmenu pull-left">
                        <ul class="nav navbar-nav collapse navbar-collapse">
                            <li><a href="/products">Products</a></li>
                            <li><a href="/news">News</a></li>
                            <li><a href="/contact">Contact</a></li>
                        </ul>
                    </div>
                </div>
                <!--<div class="col-sm-3">
                    <div class="search_box pull-right">
                        <input type="text" placeholder="Search"/>
                    </div>
                </div>-->
            </div>
        </div>
    </div><!--/header-bottom-->
</header><!--/header-->
