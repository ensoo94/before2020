(function ()
{
    'use strict';

    angular
        .module('fuse')
        .config(routeConfig);

    /** @ngInject */
    function routeConfig($stateProvider, $urlRouterProvider, $locationProvider, $httpProvider, $sessionStorageProvider)
    {
        $locationProvider.html5Mode(true);

        $urlRouterProvider.otherwise('/login');

        $stateProvider
            .state('app', {
                abstract: true,
                views   : {
                    'main@'         : {
                        templateUrl: 'app/core/layouts/main.html',
                        controller : 'MainController as vm'
                    },
                    'toolbar@app'   : {
                        templateUrl: 'app/toolbar/layouts/toolbar.html',
                        controller : 'ToolbarController as vm'
                    },
                    'quickPanel@app': {
                        templateUrl: 'app/quick-panel/quick-panel.html',
                        controller : 'QuickPanelController as vm'
                    }
                },
                resolve: {
                    PeerData: function ($http)
                    {
                        //임시
                        var obj = $http.get('./app/data/quick-panel/peer.json');
                        return obj;
                    },
                    RequestData: function ($http)
                    {
                        //임시
                        var obj = $http.get('./app/data/quick-panel/request.json');
                        return obj;
                    },                 
                    RecentwikiData: function ($http)
                    {
                        var obj;
                        obj = $http.get('../xwiki/rest/wikis/xwiki/modifications?start=0&number=100');
                        return obj;
                    }
                    
                }
            });
    }

})();
